#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "../include/ast.hpp"

using namespace std;

vector<string> dotdata; //.data
vector<string> dottext; //.text
unordered_map<string, int> st; //Tabela de Símbolos
int regCounter = 0;
int regCounterS = 0;
int whiles = 0;

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

string allocateRegisterSMM() {
    return "$s" + to_string(regCounterS-1);
}

string allocateRegisterMM() {
    return "$t" + to_string(regCounter-1);
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

    } else if(node.value == "ativacao"){
        if(node.children.size()>1){ //Ou seja se args tiver filho, tipo tiver args
            dottext.push_back("\tmove $a0, " + generateExpression(*node.children[1]->children[0]));

        }
        dottext.push_back("\tjal " + treatIDNUM(node.children[0]->value));
        if(treatIDNUM(node.children[0]->value) == "output"){
            dottext.push_back("\tli $v0, 10");
            dottext.push_back("\tsyscall");
            return "";

        } else if(treatIDNUM(node.children[0]->value) == "input"){
            return "$v0";
        }

    } else if(!node.value.empty() && node.value.at(0) == 'N'){
        dottext.push_back("\tli " + allocateRegisterM() + ", " + to_string(treatNUM(node.value))); 
        return allocateRegister();

    } else if(!node.value.empty() && node.value.at(0) == 'v'){
        if(node.children.size() > 1){ //Se for um vetor 
            string tnumber = generateExpression(*node.children[1]);
            dottext.push_back("\tla " + allocateRegister() + ", " + treatIDNUM(node.children[0]->value));
            dottext.push_back("\tmul " + allocateRegisterM() + ", " + tnumber + ", 4");
            dottext.push_back("\tadd " + allocateRegisterM() + ", " + allocateRegisterM() + ", " + allocateRegisterMM());
            dottext.push_back("\tlw " + allocateRegisterSM() + ", 0(" + allocateRegisterM() + ")");
            return allocateRegisterS(); 

        } else { //Se for um var normal
            dottext.push_back("\tlw " + allocateRegisterM() + ", " + treatIDNUM(node.children[0]->value));
            return allocateRegister(); 
        }
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

    } else if(node.value == "while"){
        int whileL = whiles++; 
        dottext.push_back("while" + to_string(whiles-1) + ":");
        if(node.children[0]->children[0]->value == "=="){
            dottext.push_back("\tbne " + generateExpression(*node.children[0]->children[0]->children[0]) + ", " + generateExpression(*node.children[0]->children[0]->children[1]) + ", exit" + to_string(whiles-1));

        } else if(node.children[0]->children[0]->value == "!="){
            dottext.push_back("\tbeq " + generateExpression(*node.children[0]->children[0]->children[0]) + ", " + generateExpression(*node.children[0]->children[0]->children[1]) + ", exit" + to_string(whiles-1));

        } else if(node.children[0]->children[0]->value == "<"){
            dottext.push_back("\tsub " + allocateRegisterSM() + ", " + generateExpression(*node.children[0]->children[0]->children[0]) + ", " + generateExpression(*node.children[0]->children[0]->children[1]));
            dottext.push_back("\tbgez " + allocateRegisterSM() + ", exit" + to_string(whileL));

        } else if(node.children[0]->children[0]->value == "<="){
            dottext.push_back("\tsub " + allocateRegisterSM() + ", " + generateExpression(*node.children[0]->children[0]->children[0]) + ", " + generateExpression(*node.children[0]->children[0]->children[1]));
            dottext.push_back("\tbgtz " + allocateRegisterSM() + ", exit" + to_string(whileL));

        } else if(node.children[0]->children[0]->value == ">"){
            dottext.push_back("\tsub " + allocateRegisterSM() + ", " + generateExpression(*node.children[0]->children[0]->children[0]) + ", " + generateExpression(*node.children[0]->children[0]->children[1]));
            dottext.push_back("\tblez " + allocateRegisterSM() + ", exit" + to_string(whileL));

        } else if(node.children[0]->children[0]->value == ">="){
            dottext.push_back("\tsub " + allocateRegisterSM() + ", " + generateExpression(*node.children[0]->children[0]->children[0]) + ", " + generateExpression(*node.children[0]->children[0]->children[1]));
            dottext.push_back("\tbltz " + allocateRegisterSM() + ", exit" + to_string(whileL));

        }
        generate(*node.children[1]);
        dottext.push_back("\tj while" + to_string(whileL));
        dottext.push_back("exit" + to_string(whileL) + ":");

    } else if(node.value == "expressao"){
        string var;
        if(node.children.size()>2){
            var = treatIDNUM(node.children[0]->children[0]->value);
            if(node.children[0]->children.size()<=1){
                dottext.push_back("\tsw " + generateExpression(*node.children[2]) + ", " + var); 

            } else {
                string registerS = generateExpression(*node.children[2]);
                string tnumber = generateExpression(*node.children[0]->children[1]);
                dottext.push_back("\tla " + allocateRegisterM() + ", " + var);
                dottext.push_back("\tmul " + tnumber + ", " + tnumber + ", 4");
                dottext.push_back("\tadd " + allocateRegisterM() + ", " + tnumber + ", " + allocateRegisterM());
                dottext.push_back("\tsw " + registerS + ", 0(" + allocateRegisterM() + ")");
            }
    
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

