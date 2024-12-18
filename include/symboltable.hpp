#pragma once

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Identifier {
    public:
        string idName;
        string idType;
        string returnType;
        vector<string> funcParams;
    Identifier(string name, string type, string returnType, vector<string> params){
        this->idType = type;
        this->idName = name;
        this->returnType = returnType;
        this->funcParams = params;
    }
};
class SymbolTable{
    public:
        vector<Identifier*> symbols;

        Identifier* findId(string nameQuery){
            for (Identifier* ID : this->symbols){
                if(ID->idName == nameQuery) return ID;
            }
            return nullptr;
        }
        //void InsertId(string name, string type, string returnType, vector<string> params){
        void InsertId(Identifier* id){    
            //Identifier* id = new Identifier(name, type, returnType, params);
            this->symbols.push_back(id);
        }
        void deleteTable(){
            for (Identifier* id : this->symbols) delete(id);
         }
};