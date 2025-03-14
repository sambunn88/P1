//scanner.cpp
//Sam bunn 3/1/25
#include <iostream>
#include "token.h"
using namespace std;

int table[6][6] = {{1000, 1, -1, 3, 5, 0},{-2, -2, 2, -2, -2, -2},{1003, 1003, 2, 1003, 1003, 1003},{-3, -3, 4, -3, -3, -3},{1002, 1002, 4, 1002, 1002, 1002},{1001, 1001, 1001, 1001, 1001, 1001}};

int resolveChar(char);
token intToToken(int, string, int) //FA Table number, character input, line number

token FADriver() {
    int state = 0;
    int nextState;
    string S = NULL;

    while (state < 1000) {
        nextState = table
    }
}

