#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "../include/ast.hpp"

using namespace std;

vector<string> dotdata; //.data
vector<string> dottext; //.text
unordered_map<string, int> st; //Tabela de Símbolos
int regCounter;
int regCounterS;

string allocateRegister() {
    return "$t" + to_string(regCounter++);
}

string allocateRegisterM() {
    return "$t" + to_string(regCounter);
}

string allocateRegisterS() {
    return "$s" + to_string(regCounterS++);
}

string allocateRegisterSM() {
    return "$s" + to_string(regCounterS);
}

void deallocateRegister() {
    regCounter--;
}

void deallocateRegisterS() {
    regCounterS--;
}

bool hasChildren(ASTNode* node) {
    return !node->children.empty();
}

int treatNUM(string NUM){
    string toReturnStr = NUM.substr(4, NUM.size()-5); //Pega o primeiro carácter depois do ( e o último antes do ).
    int toReturn = stoi(toReturnStr); //Traduz pra inteiro
    return toReturn;
}

string treatIDNUM(string IDNUM){
    string toReturn = IDNUM.substr(3, IDNUM.size()-4); //Pega o primeiro carácter depois do ( e o último antes do ).
    return toReturn; 
}

string generateExpression(ASTNode &node){

    if(node.value == "PLUS"){
        dottext.push_back("\tadd " + allocateRegisterSM() + ", " + generateExpression(*node.children[0]) + ", " + generateExpression(*node.children[1]));
        return allocateRegisterS();

    } else if(node.value == "MINUS"){
        dottext.push_back("\tsub " + allocateRegisterSM() + ", " + generateExpression(*node.children[0]) + ", " + generateExpression(*node.children[1]));
        return allocateRegisterS();

    } else if(node.value == "TIMES"){
        dottext.push_back("\tmul " + allocateRegisterSM() + ", " + generateExpression(*node.children[0]) + ", " + generateExpression(*node.children[1]));
        return allocateRegisterS();

    } else if(node.value == "div"){
        dottext.push_back("\tdiv " + generateExpression(*node.children[0]) + ", " + generateExpression(*node.children[1]));
        dottext.push_back("\tmfhi " + allocateRegisterSM());
        return allocateRegisterS();

    } else if(node.value == "expressao"){
        return generateExpression(*node.children[0]);;

    } else if(!node.value.empty() && node.value.at(0) == 'N'){
        dottext.push_back("\tli " + allocateRegisterM() + ", " + to_string(treatNUM(node.value))); 
        return allocateRegister();

    } else if(!node.value.empty() && node.value.at(0) == 'v'){
        dotdata.push_back("\tli " + allocateRegisterM() + ", " + to_string(treatNUM(node.value))); 
        return allocateRegister();
    }
}

void generate(ASTNode &node){
    if (node.value == "programa") {
        for (ASTNode* child : node.children) {
            generate(*child); 
        }
    
    } else if (node.value == "statement") {
        for (ASTNode* child : node.children) {
            generate(*child); 
        }

    } else if(node.value == "fun-declaracao"){
        string funcName = treatIDNUM(node.children[1]->value);
        if(node.children[0]->value == "int"){
            dotdata.push_back(funcName + ": .word 0");
        }
         //Pega o nome da função
        dottext.push_back(funcName + ":"); //Cria função no MIPS
        generate(*node.children[3]); //Gera o corpo da requisição

    } else if(node.value == "var-declaracao"){
        string ID = treatIDNUM(node.children[1]->value);
        if(node.children.size()<3){ //Se não for um array de inteiros
            st[ID] = 0;
            dotdata.push_back(ID + ": .word 0");   

        } else { //Se for um array de inteiros
            int sizeorvalue = treatNUM(node.children[2]->value);
            st[ID] = 0;
            dotdata.push_back(ID + ": .space " + to_string(sizeorvalue*4));  
        }  

    } else if(node.value == "expressao"){
        string var;
        if(node.children.size()>2){
            var = treatIDNUM(node.children[0]->children[0]->value);
            dottext.push_back("\tsw " + generateExpression(*node.children[2]) + ", " + var);  
    
        } else {
            generateExpression(*node.children[0]);
        }
        regCounter = 0;
        regCounterS = 0;

    } else {
        if(hasChildren(&node)){
            for (ASTNode* child : node.children) {
                generate(*child); 
            }
        }
    }
}

void includeInstructions(){
    //Cabeçalhos
    dotdata.push_back(".data");
    dottext.push_back(".text");
    dottext.push_back("\tjal main");
    //Função de input
    dottext.push_back("input:");
    dottext.push_back("\tli   $v0, 5");
    dottext.push_back("\tsyscall");
    dottext.push_back("\tjr   $ra");
    //Função de output
    dottext.push_back("output:");
    dottext.push_back("\tli   $v0, 1");
    dottext.push_back("\tsyscall");
    dottext.push_back("\tli   $v0, 11");
    dottext.push_back("\tli   $a0, 10");
    dottext.push_back("\tsyscall");
    dottext.push_back("\tjr   $ra");
    
}

