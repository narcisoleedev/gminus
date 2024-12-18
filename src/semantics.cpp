#include <string>
#include <iostream>
#include <vector>
#include "../include/symboltable.hpp"
#include "../include/ast.hpp"

using namespace std;

bool validCode = true;

bool getValidCode () { return validCode; }
vector<SymbolTable*> tables;

Identifier* searchTables(string name){
    for (int i = size(tables) - 1; i>= 0; i--){
        Identifier* id = tables[i]->findId(name);
        if(id != nullptr) { return id; }
    }
    return nullptr;
}
void semanticAnalysis(ASTNode* n){
    
    //Criar uma tabela nova quando muda de escopo
    if(n->value == "programa") {
        tables.push_back(new SymbolTable());
    }

    //Pega a tabela do escopo atual
    SymbolTable* currentTable = tables[(size(tables))-1];

    //Iterar os nós da árvore
    int childIndex = 0;
    for (childIndex; childIndex < size(n->children);){
        ASTNode* node = n->children[childIndex];

        //Pegar declaração de variáveis
        if(node->value == "var-declaracao"){
            string name = node->children[1]->value;
            name = name.substr(3, name.size()-4);
            Identifier* id = currentTable->findId(name);
            
            //Variável já declarada no mesmo escopo
            if(id != nullptr){
                cout << "The variable " + name + " was declared more than once in the same scope." << endl;
                validCode = false;
            }

            //Inserindo variável
            else {
                id = size(node->children) == 3 ? new Identifier(name, "vector", "", {})
                                           : new Identifier(name, "int", "", {});
            currentTable->InsertId(id);
            }
        }

        //Chamando variáveis
        if(node->value == "var"){
            string name = node->children[0]->value;
            name = name.substr(3, name.size()-4);
            Identifier* id = searchTables(name);

            //Variável não declarada
            if(id == nullptr){
                cout << "Variable " << name << " was not declared" << endl;
                validCode = false;
            }

            //Verificando se a variável foi usada corretamente
            else {
                string type = id->idType;
                if(type == "vector" && size(node->children) == 1){
                    cout << "Cant assign integer value to vector " << name << "." << endl;
                    validCode = false;
                }
                if(type == "int" && size(node->children) == 2){
                    cout << "Cant access index of integer " << name << "." <<endl;
                    validCode = false;
                }
            }
        }

        //Declarando Função
        if(node->value == "fun-declaracao"){
            string name = node->children[1]->value;
            name = name.substr(3, name.size()-4);
            Identifier* id = searchTables(name);

            //Função já declarada
            if(id != nullptr){
                cout << "The function " + name + " was declared more than once." << endl;
                validCode = false;
            }

            //Inserindo função
            else {
                //Pegando tipo de retorno e parâmetros
                string returnType = node->children[0]->value;
                ASTNode* params = node->children[2];

                //Verificando se eh uma função sem parâmetros
                if(params->children[0]->value == "void"){
                    id = new Identifier(name, "function", returnType, {});
                    tables[0]->InsertId(id);

                    //Criando nova tabela de símbolos para o escopo dessa função
                    tables.push_back(new SymbolTable());
                }
                
                //Lidando com parâmetros
                else {
                    vector<string> paramsNames;
                    vector<string> paramsLista;
                    for (ASTNode* param : params->children){

                        //Parâmetro vetor
                        if(size(param->children) == 3){

                            //Inserir Parâmetro na tabela de símbolos (escopo da declaração da função)
                            string paramName = param->children[1]->value;
                            paramName = paramName.substr(3, paramName.size()-4);

                            //Inserir parâmetro no vetor de parâmetros
                            paramsNames.push_back(paramName);
                            paramsLista.push_back("vector");
                            continue;
                        }

                        //Mesma coisa pra parâmetro int
                        string paramName = param->children[1]->value;
                        paramName = paramName.substr(3, paramName.size()-4);
                        paramsNames.push_back(paramName);
                        paramsLista.push_back("int");
                    }
                    id = new Identifier(name, "function", returnType, paramsLista);
                    tables[0]->InsertId(id);

                    tables.push_back(new SymbolTable());
                    currentTable = tables[(size(tables))-1];    

                    //Inserindo parâmetros dentro do escopo da função
                    for(int p = 0; p<size(paramsNames); p++){
                            Identifier* paramVar = new Identifier(paramsNames[p], paramsLista[p], "", {});
                            currentTable->InsertId(paramVar);
                    }
                }
            }
        }

        //Chamando Função (exceto 'output' e 'input' pois são funções especiais)
        if(node->value == "ativacao" && node->children[0]->value != "ID(output)" && node->children[0]->value != "ID(input)"){
            string name = node->children[0]->value;
            name = name.substr(3, name.size()-4);
            Identifier* id = searchTables(name);

            //Variável não declarada
            if(id == nullptr){
                cout << "Function " << name << " was not declared" << endl;
                validCode = false;
            }

            //Verificando se a função foi usada corretamente
            else {

                //Quantos parâmetros tem a função
                int paramLength = size(id->funcParams);
                //Quantos argumentos foram passados
                int argLength = size(node->children) > 1 ? size(node->children[1]->children)
                                                          : 0;
                //Argumentos e parâmetros não batem
                if(argLength != paramLength){
                    cout << "Function " << name << " expected " << paramLength << " arguments but got " << argLength << endl;
                    validCode = false;
                }
            } 
        }

        //Chamando a função recursivamente para os filhos
        if(childIndex < size(n->children)) semanticAnalysis(n->children[childIndex]);
        childIndex++;
    }
    //Deleta a tabela atual quando sai do escopo
    if(n->value == "programa") {
        Identifier* id = searchTables("main");

        //Sem função main
        if(id == nullptr){
            cout << "No main function found." << endl;
            validCode = false;
        }
        tables.pop_back();
    }
     if(size(tables)>1 && n->value == "fun-declaracao") {
        tables.pop_back();
    }
}
