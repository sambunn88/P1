//testScanner.cpp
//Sam Bunn 3/1/25
#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#ifndef _TOKEN_H_
#define _TOKEN_H_
#include "token.h"
#endif
#include "scanner.h"
using namespace std;

string tokenNames[] = {"End of File Token", "t1 token", "t2 token", "t3 token"}; //OR1

void printToken(token* tk) {
    cout << tokenNames[tk->type] << "\t" << tk->text << "\t" << tk->line << endl;
}

void testScanner(string fileName) {
    string processedFileName = "processFile";
    FILE* processFile;
    const char* inputFileCStr = processedFileName.c_str();
    processFile = fopen(inputFileCStr,"w+");
    const char* inputFileCStr2 = fileName.c_str();
    FILE* inFile = fopen(inputFileCStr2, "r");

    //Preprocess file and create new file without comments ensure that only valid characters are in the file
    char ch;
    bool comment = false;
    while ((ch = fgetc(inFile)) != EOF) {
        if (comment) {
            //During comment
            if (ch == '*') {
                comment = false;
                fprintf(processFile, " ");
            }
            else if (ch == '\n') {
                fprintf(processFile, "\n");
            }
            else {
                fprintf(processFile, " ");
            }
        }
        else {
            if (ch == '*') {
                comment = true;
                fprintf(processFile, " ");
            }
            else if (isdigit(ch) || isalpha(ch) || isspace(ch) || (ch >= 33 && ch <= 43))  { //OR1
                fprintf(processFile, "%c", ch);
            }  
            else {
                fprintf(stderr, "\nProcessing Error: Invalid Character Found  %c\n", ch); 
                exit (1); 
            }
        }
    }

    fclose(processFile);
    fclose(inFile);

    FILE* processFileRead = fopen(inputFileCStr,"r");
    bool eofFound = false;

    //Call scanner until EOF Token
    while(!eofFound) {
        token* tk = scanner(processFileRead);

        if (tk == nullptr) {    //Start OR1
            cerr << "Error: Null token encountered!" << endl;
            break;
        } //End OR1

        //Print token
        printToken(tk);

        //Check if EOF
        if (tk->type == 0) {
            eofFound = true;
        }
    }

    //Close processFile
    fclose(processFileRead);
    remove(inputFileCStr);
}