#include <string>
#include <fstream>
#include <iostream>

#include "header.hpp"

using namespace std;

int main(int argc, char *argv[]){
    ifstream file(argv[1]);
    string line;

    if(file.is_open()){
        while(getline(file, line)){
            for(Token& token: getTokens(line)){
                cout << token.getToken() << "\n";
            }
        }
        file.close();
    } else {
        cerr << "Unable to open file for some reason buddy." << "\n";
    }
    return 0;
}