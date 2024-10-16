#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "lexer.hpp"

using namespace std;

int main(int argc, char *argv[]){
    ifstream file(argv[1]);
    string line;

    if(file.is_open()){
        stringstream buffer;
        buffer << file.rdbuf(); 
        std::string fileContent = buffer.str();
        for (Token token : getTokens(fileContent)) {
            cout << "Row:" << token.line << "|" << token.lex << "|" << token.attr << "|" << std::endl;
        }
    } else {
        cerr << "Unable to open file for some reason buddy." << "\n";
    }
    file.close();
    return 0;
}