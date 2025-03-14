//token.h
//Sam Bunn 3/1/25
#include <string>

enum tokenID {EOF_tk, t1_tk, t2_tk, t3_tk};
string tokenNames[] ={"End of File Token", "t1 token", "t2 token", “t3 token”};
struct token {tokenID, string, int}; //string is comprised of the characters in the specific token, int is the line #


