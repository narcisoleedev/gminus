#pragma once

#include <string>
#include <vector>

using namespace std;

enum class tp{
    ID,
    NUM, 
    ERROR
};

class Token{
    private:
        string lex;
        tp typeLex;

    public:
        Token(string lex, tp typeLex){
            this->lex = lex;
            this->typeLex = typeLex;
        }
        string getToken(){
            return lex;
        }
};

vector<Token> getTokens(string& line);

