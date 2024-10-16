#pragma once

#include <string>
#include <vector>

using namespace std;

/*enum class tp{
    ID,
    KEYWORD,
    NUM, 
    SYMBOL,
    BLANK,
    COMMENT,
    ENDOFFILE,
    ERROR
};*/

class Token{

    public:
        string lex;
        string typeLex;
        string attr;
        int line;
        Token(string lex, string typeLex, string attr, int line){
            this->lex = lex;
            this->typeLex = typeLex;
            this->attr = attr;
            this->line = line;
        }
    
};

vector<Token> getTokens(string& line); //getTokens

vector<string> getSymbolTable(); //Symbol Table

