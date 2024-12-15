#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "./include/lexer.hpp"
#include "./include/ast.hpp"
#include "./include/generator.hpp"

using namespace std;

int yyparse();
int yylex();
AST* yytree();

int main(int argc, char *argv[]){
    ifstream file(argv[1]);
    string line;
    int c=0;

    if(file.is_open()){
        stringstream buffer;
        buffer << file.rdbuf(); 
        std::string fileContent = buffer.str();
        //cout << "LEX TABLE" << endl;
        //cout << "ROW|LEX|TOKEN|ATTRIBUTE" << endl;
        for (Token token: getTokens(fileContent)) {
            //cout << "Row:" << token.line << "|" << token.lex << "|" << token.typeLex << "|" << token.attr << "|" << std::endl;
            c++;
        }
    } else {
        cerr << "Unable to open file for some reason buddy." << "\n";
    }
    file.close();
    // cout << "\n";
    // cout << "SYMBOL TABLE" << endl;
    // for(string str: getSymbolTable()){
    //     cout << str << "|" << endl;
    // }
    // cout << "\n";

    //yytree só pode ser chamada depois de yyparse
    AST* ast;
    yyparse();
    ast = yytree();
    ast->printTree();
    includeInstructions();
    /*generate(*ast->root);
    for (std::string ins: dotdata) {
        std::cout << ins << endl;
    }
    for (std::string ins: dottext) {
        std::cout << ins << endl;
    }*/
}