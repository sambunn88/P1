//token.h
//Sam Bunn 3/1/25
#include <string>
using namespace std;

enum tokenIDs {EOF_tk, t1_tk, t2_tk, t3_tk};

struct token {
    int type; 
    string text; 
    int line;
}; 