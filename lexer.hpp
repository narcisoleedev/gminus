#pragma once

#include <string>
#include <vector>

using namespace std;

enum class tp{
    ID,
    KEYWORD,
    NUM, 
    SYMBOL,
    BLANK,
    COMMENT,
    ENDOFFILE,
    ERROR
};

class Token{
    /*private:
        string lex;
        tp typeLex;
        string attr;
        int line;*/

    public:
        string lex;
        tp typeLex;
        string attr;
        int line;
        Token(string lex, tp typeLex, string attr, int line){
            this->lex = lex;
            this->typeLex = typeLex;
            this->attr = attr;
            this->line = line;
        }
    
};

vector<Token> getTokens(string& line);

