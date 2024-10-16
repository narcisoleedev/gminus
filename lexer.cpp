#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <locale>
#include "lexer.hpp"

int row = 0;

vector<string> symbolTable; //Symbol Table

int checkIfInST(string lex){
    if(symbolTable.size()>0){
        int i = 1;
        for(string comp: symbolTable){
            if(lex==comp){
                return i;
            }
            i++;
        } 
    }
    return 0;
}

int iswhitespace(char bs) {

    if (bs == '\n') { 
        return 2;  
    } else if (isblank(bs)) {
        return 1;  
    }
    return 0;
}

int issymbol(char character) {

    switch (character) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '<':
        case '>':
        case '=':
        case '!':
        case ';':
        case ',':
        case '(':
        case ')':
        case '[':
        case ']':
        case '{':
        case '}':
        case '.':
            return 1;  

        case EOF:
            return 0; 

        default:
            if(std::isalpha(std::tolower(character, std::locale("pt_BR.UTF-8")), std::locale("pt_BR.UTF-8"))) return 0;
            else if(isdigit(character)) return 0;
            else if(iswhitespace(character)) return 0;
            return -1;  
    }
}

string iserror(char character){
    if(issymbol(character)!=-1) return "symbol";
    return "error";
}

std::vector<string> getSymbolTable(){
    return symbolTable;
}

std::vector<Token> getTokens(string& file){

    std::vector<Token> tokens;
    
    for(int i=0; i<file.size(); i++){

        if(std::isalpha(std::tolower(file[i], std::locale("pt_BR.UTF-8")), std::locale("pt_BR.UTF-8"))){ //CHECK IF ITS A ID

            string lex = "";
            while(i < file.size() && std::isalpha(std::tolower(file[i], std::locale("pt_BR.UTF-8")), std::locale("pt_BR.UTF-8"))){ //WHILE ID
                lex+=file[i];
                i++;
            }
            if(isdigit(file[i])){
                Token token = Token("ERROR", "error", "", row);
                tokens.push_back(token);
            } else {
                if(lex == "if"){
                    Token token = Token(lex, lex, "", row);
                    tokens.push_back(token);
                } else if(lex == "else"){
                    Token token = Token(lex, lex, "", row);
                    tokens.push_back(token);
                } else if(lex == "int"){
                    Token token = Token(lex, lex, "", row);
                    tokens.push_back(token);
                } else if(lex == "return"){
                    Token token = Token(lex, lex, "", row);
                    tokens.push_back(token);
                } else if(lex == "void"){
                    Token token = Token(lex, lex, "", row);
                    tokens.push_back(token);
                } else if(lex == "while"){
                    Token token = Token(lex, lex, "", row);
                    tokens.push_back(token);
                } else if(lex == "do"){
                    Token token = Token(lex, lex, "", row);
                    tokens.push_back(token);
                } else if(lex == "for"){
                    Token token = Token(lex, lex, "", row);
                    tokens.push_back(token);
                } else {

                    int pos = checkIfInST(lex);
                    if(pos){
                        int posm = pos-1;
                        Token token = Token(lex, "id", to_string(posm), row);
                        tokens.push_back(token);
                    } else {
                        symbolTable.push_back(lex);
                        int sizeArr = symbolTable.size() - 1;
                        Token token = Token(lex, "id", to_string(sizeArr), row);
                        tokens.push_back(token);
                    }
                }
            }
            i--;
    
        } else if (isdigit(file[i])){ //VERIFY IF ITS A NUM

            string lex = "";
            while(i < file.size() && isdigit(file[i])){ //WHILE NUM
                lex+=file[i];
                i++;
            }
            if(std::isalpha(std::tolower(file[i], std::locale("pt_BR.UTF-8")), std::locale("pt_BR.UTF-8"))){
                Token token = Token("ERROR", "error", "", row);
                tokens.push_back(token);
            } else {
                int pos = checkIfInST(lex);
                    if(pos){
                        int posm = pos-1;
                        Token token = Token(lex, "number", to_string(posm), row);
                        tokens.push_back(token);
                    } else {
                        symbolTable.push_back(lex);
                        int sizeArr = symbolTable.size() - 1;
                        Token token = Token(lex, "number", to_string(sizeArr), row);
                        tokens.push_back(token);
                    }
            }
            i--;
    
        } else if(iswhitespace(file[i])) {

            string lex(1, file[i]);
            if (iswhitespace(file[i]) == 1) {
                Token token = Token(lex, "", "", row);
                tokens.push_back(token);

            } else if (iswhitespace(file[i]) == 2) {
                Token token = Token("\\n", "", "", row);
                tokens.push_back(token);
                row++; 
            }

        } else if (issymbol(file[i])) {

            string lex = "";
            while (i < file.size() && issymbol(file[i]) && lex.length() < 2) {
                lex += file[i];
                i++;
            }    

            if(lex=="//"){ //one-file comment
                Token token = Token(lex, "symbol", "", row);
                tokens.push_back(token);
                while (i < file.size() && file[i] != '\n') {
                    i++;
                }
                row++;

            } else if (lex == "/*") {
                Token token = Token(lex, "symbol", "", row);
                tokens.push_back(token);

                bool closed = false;
                while (i < file.size()) {
                    if (i + 1 < file.size() && file[i] == '*' && file[i + 1] == '/') {
                        Token token = Token("*/", "symbol", "", row);
                        tokens.push_back(token);
                        i++;
                        closed = true;
                        break;
                    }
                    if (file[i] == '\n') {
                        row++; 
                    }
                    i++;
                }
                if (!closed) {
                    Token error_token = Token("Unclosed Comment", "error", "", row);
                    tokens.push_back(error_token);
                }

            } else {
                if(lex=="<"){
                    Token token = Token(lex, "relop", "LT", row);
                    tokens.push_back(token);
                } else if (lex=="<="){
                    Token token = Token(lex, "relop", "LE", row);
                    tokens.push_back(token);
                } else if (lex==">"){
                    Token token = Token(lex, "relop", "GT", row);
                    tokens.push_back(token);
                } else if (lex==">="){
                    Token token = Token(lex, "relop", "GE", row);
                    tokens.push_back(token);
                } else if (lex=="=="){
                    Token token = Token(lex, "relop", "EQ", row);
                    tokens.push_back(token);
                } else if (lex=="!="){
                    Token token = Token(lex, "relop", "NE", row);
                    tokens.push_back(token);
                } else if (lex=="+"){
                    Token token = Token(lex, "symbol", "", row);
                    tokens.push_back(token);
                } else if (lex=="-"){
                    Token token = Token(lex, "symbol", "", row);
                    tokens.push_back(token);
                } else if (lex=="*"){
                    Token token = Token(lex, "symbol", "", row);
                    tokens.push_back(token);
                } else if (lex==";"){
                    Token token = Token(lex, "symbol", "", row);
                    tokens.push_back(token);
                } else if (lex=="("){
                    Token token = Token(lex, "symbol", "", row);
                    tokens.push_back(token);
                } else if (lex==")"){
                    Token token = Token(lex, "symbol", "", row);
                    tokens.push_back(token);
                } else if (lex=="["){
                    Token token = Token(lex, "symbol", "", row);
                    tokens.push_back(token);
                } else if (lex=="]"){
                    Token token = Token(lex, "symbol", "", row);
                    tokens.push_back(token);
                } else if (lex=="{"){
                    Token token = Token(lex, "symbol", "", row);
                    tokens.push_back(token);
                } else if (lex=="}"){
                    Token token = Token(lex, "symbol", "", row);
                    tokens.push_back(token);
                } else if (lex=="="){
                    Token token = Token(lex, "symbol", "", row);
                    tokens.push_back(token);
                } else {

                    if(lex.length()==2){
                        string a = string(1, lex[0]);
                        Token tokenA = Token(a, iserror(lex[0]), "", row);
                        tokens.push_back(tokenA);
                        string b = string(1, lex[1]);
                        Token tokenB = Token(b, iserror(lex[1]), "", row);
                        tokens.push_back(tokenB);

                    } else {
                        Token token = Token(lex, "error", "", row);
                        tokens.push_back(token);
                    }
                }
                i--;
            }
        }
    }
    return tokens;
} 