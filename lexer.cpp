#include <vector>
#include <string>
#include <cctype>
#include "header.hpp"

using namespace std;

vector<Token> getTokens(string& line){

    vector<Token> tokens;
    for(int i=0; i<line.size(); i++){
        if(isalpha(line[i])){ //CHECK IF ITS A ID

            string lex = "";
            while(isalpha(line[i])){
                lex+=line[i];
                i++;
            }
            if(isdigit(line[i])){
                Token token = Token("ERROR", tp::ERROR);
                tokens.push_back(token);
            } else {
                Token token = Token(lex, tp::ID);
                tokens.push_back(token);
            }
    
        } else if (isdigit(line[i])){

            string lex = "";
            while(isdigit(line[i])){ //CHECK IF ITS A NUM
                lex+=line[i];
                i++;
            }
            if(isalpha(line[i])){
                Token token = Token("ERROR", tp::ERROR);
                tokens.push_back(token);
            } else {
                Token token = Token(lex, tp::NUM);
                tokens.push_back(token);
            }
    
        }
    }
    return tokens;
}

