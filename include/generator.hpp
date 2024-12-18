#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "../include/ast.hpp"
#include "../include/symboltable.hpp"

using namespace std;

vector<string> dotdata; //.data
vector<string> dottext; //.text
unordered_map<string, int> st; //Tabela de Símbolos
vector<SymbolTable*> tablesST; //Tabela de Símbolos
int regCounter = 0;
int regCounterS = 0;
int whiles = 0;
int ifs = 0;
bool isLocal = false;
int offset = 0;

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

Identifier* searchTablesST(string name){
    for (int i = size(tablesST) - 1; i>= 0; i--){
        Identifier* id = tablesST[i]->findId(name);
        if(id != nullptr) { return id; }
    }
    return nullptr;
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
            int count = 0;
            for(ASTNode* child: node.children[1]->children){
                dottext.push_back("\tmove $a" + to_string(count) + ", " + generateExpression(*child));
                count++;
            }
        }
        dottext.push_back("\tjal " + treatIDNUM(node.children[0]->value));
        if(treatIDNUM(node.children[0]->value) == "output"){
            dottext.push_back("\tli $v0, 10");
            dottext.push_back("\tsyscall");
            return "";

        } else if(treatIDNUM(node.children[0]->value) == "input"){
            return "$v0";
        }
        return "$v0";

    } else if(!node.value.empty() && node.value.at(0) == 'N'){
        dottext.push_back("\tli " + allocateRegisterM() + ", " + to_string(treatNUM(node.value))); 
        return allocateRegister();

    } else if(!node.value.empty() && node.value.at(0) == 'v'){

        string var = treatIDNUM(node.children[0]->value);
        Identifier* id = searchTablesST(var);
        if(id->returnType==""){
            if(node.children.size() > 1){ //Se for um vetor 
                string tnumber = generateExpression(*node.children[1]);
                dottext.push_back("\tla " + allocateRegister() + ", " + var);
                dottext.push_back("\tmul " + allocateRegisterM() + ", " + tnumber + ", 4");
                dottext.push_back("\tadd " + allocateRegisterM() + ", " + allocateRegisterM() + ", " + allocateRegisterMM());
                dottext.push_back("\tlw " + allocateRegisterSM() + ", 0(" + allocateRegisterM() + ")");
                return allocateRegisterS(); 

            } else { //Se for um var normal
                dottext.push_back("\tlw " + allocateRegisterM() + ", " + treatIDNUM(node.children[0]->value));
                return allocateRegister(); 
            }

        } else {
            if(node.children.size() > 1){ //Se for um vetor 
                string tnumber = generateExpression(*node.children[1]);
                dottext.push_back("\taddi " + allocateRegisterSM() + ", $sp, " + to_string((offset - (stoi(id->returnType)) -1)*4)); //MUDEI AQ TBM EM
                dottext.push_back("\tmul " + tnumber + ", " + tnumber + ", 4");
                dottext.push_back("\tsub " + allocateRegisterSM() + ", " + allocateRegisterSM() + ", " + tnumber);
                dottext.push_back("\tlw " + allocateRegisterSM() + ", 0(" + allocateRegisterS() + ")");
                return allocateRegisterSM(); 

            } else { //Se for um var normal
                dottext.push_back("\tlw " + allocateRegisterM() + ", " + to_string(((offset-(stoi(id->returnType))-1)*4)) +"($sp)"); //MUDEI AQ TBM EM
                return allocateRegister(); 
            }
        }
    }
}

void generate(ASTNode &node){
    if (node.value == "programa") {
        tablesST.push_back(new SymbolTable());
        SymbolTable* currentTable = tablesST[(size(tablesST))-1];
        for (ASTNode* child : node.children) {
            generate(*child); 
        }
        tablesST.pop_back();
    
    } else if (node.value == "statement") {
        for (ASTNode* child : node.children) {
            generate(*child); 
        }

    } else if(node.value == "fun-declaracao"){
        isLocal = true;
        tablesST.push_back(new SymbolTable());
        SymbolTable* currentTable = tablesST[(size(tablesST))-1];
        string funcName = treatIDNUM(node.children[1]->value);
        //Pega o nome da função
        dottext.push_back(funcName + ":"); //Cria função no MIPS
        dottext.push_back("\tsub $sp, $sp, 4");
        dottext.push_back("\tsw $ra, 0($sp)"); //MUDEI AQ EM
        offset++;
        if(node.children[2]->children[0]->value != "void"){
            int count = 0;
            for(ASTNode* param: node.children[2]->children){
                string ID = treatIDNUM(param->children[1]->value);
                if(param->children.size()<3){ //Se não for um array de inteiros
                    Identifier* idObj = new Identifier(ID, "int", to_string(offset), {});
                    currentTable->InsertId(idObj);
                    dottext.push_back("\tsub $sp, $sp, 4");
                    dottext.push_back("\tmove " + allocateRegisterSM() + ", $a" + to_string(count));
                    dottext.push_back("\tsw  " + allocateRegisterSM() + ", 0($sp)");
                    offset++;

                } else { //Se for um array de inteiros
                   //NÃO IMPLEMENTADO AINDA PAE
                } 
                count++;
            }
        }
        generate(*node.children[3]); //Gera o corpo da requisição
        if(node.children[0]->value == "void"){
            dottext.push_back("\tlw $ra, " + to_string((offset-1)*4) + "($sp)");
            dottext.push_back("\tadd $sp, $sp, " + to_string(offset*4));
            dottext.push_back("\tjr $ra");
        }
        offset = 0;
        tablesST.pop_back();
        isLocal = false;

    } else if(node.value == "var-declaracao"){
        string ID = treatIDNUM(node.children[1]->value);
        SymbolTable* currentTable = tablesST[(size(tablesST))-1]; 
        if(isLocal==false){
            if(node.children.size()<3){ //Se não for um array de inteiros
                //st[ID] = 0;
                dotdata.push_back(ID + ": .word 0"); 
                Identifier* idObj = new Identifier(ID, "int", "", {});
                currentTable->InsertId(idObj);

            } else { //Se for um array de inteiros
                int sizeorvalue = treatNUM(node.children[2]->value);
                //st[ID] = 0;
                dotdata.push_back(ID + ": .space " + to_string(sizeorvalue*4)); 
                Identifier* idObj = new Identifier(ID, "vector", "", {});
                currentTable->InsertId(idObj); 
            }  

        } else {

            if(node.children.size()<3){ //Se não for um array de inteiros
                //st[ID] = 0;
                Identifier* idObj = new Identifier(ID, "int", to_string(offset), {});
                currentTable->InsertId(idObj);
                dottext.push_back("\tsub $sp, $sp, 4");
                dottext.push_back("\tli " + allocateRegisterSM() + ", 0");
                dottext.push_back("\tsw  " + allocateRegisterSM() + ", 0($sp)");
                offset++;

            } else { //Se for um array de inteiros
                int sizeorvalue = treatNUM(node.children[2]->value);
                //st[ID] = 0;
                Identifier* idObj = new Identifier(ID, "vector", to_string(offset), {});
                currentTable->InsertId(idObj);
                dottext.push_back("\tsub $sp, $sp, " + to_string(4*sizeorvalue));
                dottext.push_back("\tsw  " + allocateRegisterSM() + ", 0($sp)");
                offset = offset + sizeorvalue; 
            } 
        }

    } else if(node.value == "if"){
        tablesST.push_back(new SymbolTable());
        SymbolTable* currentTable = tablesST[(size(tablesST))-1];
        int ifL = ifs++;
        if(node.children.size()==3){
            if(node.children[0]->children[0]->value == "=="){
                dottext.push_back("\tbne " + generateExpression(*node.children[0]->children[0]->children[0]) + ", " + generateExpression(*node.children[0]->children[0]->children[1]) + ", else" + to_string(ifs-1));

            } else if(node.children[0]->children[0]->value == "!="){
                dottext.push_back("\tbeq " + generateExpression(*node.children[0]->children[0]->children[0]) + ", " + generateExpression(*node.children[0]->children[0]->children[1]) + ", else" + to_string(ifs-1));

            } else if(node.children[0]->children[0]->value == "<"){
                dottext.push_back("\tsub " + allocateRegisterSM() + ", " + generateExpression(*node.children[0]->children[0]->children[0]) + ", " + generateExpression(*node.children[0]->children[0]->children[1]));
                dottext.push_back("\tbgez " + allocateRegisterSM() + ", else" + to_string(ifL));

            } else if(node.children[0]->children[0]->value == "<="){
                dottext.push_back("\tsub " + allocateRegisterSM() + ", " + generateExpression(*node.children[0]->children[0]->children[0]) + ", " + generateExpression(*node.children[0]->children[0]->children[1]));
                dottext.push_back("\tbgtz " + allocateRegisterSM() + ", else" + to_string(ifL));

            } else if(node.children[0]->children[0]->value == ">"){
                dottext.push_back("\tsub " + allocateRegisterSM() + ", " + generateExpression(*node.children[0]->children[0]->children[0]) + ", " + generateExpression(*node.children[0]->children[0]->children[1]));
                dottext.push_back("\tblez " + allocateRegisterSM() + ", else" + to_string(ifL));

            } else if(node.children[0]->children[0]->value == ">="){
                dottext.push_back("\tsub " + allocateRegisterSM() + ", " + generateExpression(*node.children[0]->children[0]->children[0]) + ", " + generateExpression(*node.children[0]->children[0]->children[1]));
                dottext.push_back("\tbltz " + allocateRegisterSM() + ", else" + to_string(ifL));

            }
            generate(*node.children[1]);
            dottext.push_back("\tj then" + to_string(ifL));
            dottext.push_back("\telse" + to_string(ifL) + ":");
            generate(*node.children[2]);
            dottext.push_back("\tj then" + to_string(ifL));
            dottext.push_back("\tthen" + to_string(ifL) + ":");

        } else {
            if(node.children[0]->children[0]->value == "=="){
                dottext.push_back("\tbne " + generateExpression(*node.children[0]->children[0]->children[0]) + ", " + generateExpression(*node.children[0]->children[0]->children[1]) + ", then" + to_string(ifs-1));

            } else if(node.children[0]->children[0]->value == "!="){
                dottext.push_back("\tbeq " + generateExpression(*node.children[0]->children[0]->children[0]) + ", " + generateExpression(*node.children[0]->children[0]->children[1]) + ", then" + to_string(ifs-1));

            } else if(node.children[0]->children[0]->value == "<"){
                dottext.push_back("\tsub " + allocateRegisterSM() + ", " + generateExpression(*node.children[0]->children[0]->children[0]) + ", " + generateExpression(*node.children[0]->children[0]->children[1]));
                dottext.push_back("\tbgez " + allocateRegisterSM() + ", then" + to_string(ifL));

            } else if(node.children[0]->children[0]->value == "<="){
                dottext.push_back("\tsub " + allocateRegisterSM() + ", " + generateExpression(*node.children[0]->children[0]->children[0]) + ", " + generateExpression(*node.children[0]->children[0]->children[1]));
                dottext.push_back("\tbgtz " + allocateRegisterSM() + ", then" + to_string(ifL));

            } else if(node.children[0]->children[0]->value == ">"){
                dottext.push_back("\tsub " + allocateRegisterSM() + ", " + generateExpression(*node.children[0]->children[0]->children[0]) + ", " + generateExpression(*node.children[0]->children[0]->children[1]));
                dottext.push_back("\tblez " + allocateRegisterSM() + ", then" + to_string(ifL));

            } else if(node.children[0]->children[0]->value == ">="){
                dottext.push_back("\tsub " + allocateRegisterSM() + ", " + generateExpression(*node.children[0]->children[0]->children[0]) + ", " + generateExpression(*node.children[0]->children[0]->children[1]));
                dottext.push_back("\tbltz " + allocateRegisterSM() + ", then" + to_string(ifL));

            }
            generate(*node.children[1]);
            dottext.push_back("\tj then" + to_string(ifL));
            dottext.push_back("\tthen" + to_string(ifL) + ":");
            tablesST.pop_back();

        }

    } else if(node.value == "while"){
        tablesST.push_back(new SymbolTable());
        SymbolTable* currentTable = tablesST[(size(tablesST))-1];
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
        dottext.push_back("\texit" + to_string(whileL) + ":");
        tablesST.pop_back();

    } else if(node.value == "expressao"){
        string var;
        if(node.children.size()>2){
            var = treatIDNUM(node.children[0]->children[0]->value);
            Identifier* id = searchTablesST(var);
            if(node.children[0]->children.size()<=1){
                if(id->returnType == ""){
                    dottext.push_back("\tsw " + generateExpression(*node.children[2]) + ", " + var); 

                } else {
                    dottext.push_back("\tsw " + generateExpression(*node.children[2]) + ", " + to_string((offset-(stoi(id->returnType))-1)*4) + "($sp)"); 

                }

            } else { 
                if(id->returnType == ""){ //Se ele for uma variável global
                    string registerS = generateExpression(*node.children[2]);
                    string tnumber = generateExpression(*node.children[0]->children[1]);
                    dottext.push_back("\tla " + allocateRegisterM() + ", " + var);
                    dottext.push_back("\tmul " + tnumber + ", " + tnumber + ", 4");
                    dottext.push_back("\tadd " + allocateRegisterM() + ", " + tnumber + ", " + allocateRegisterM());
                    dottext.push_back("\tsw " + registerS + ", 0(" + allocateRegisterM() + ")");

                } else {
                    string registerS = generateExpression(*node.children[2]);
                    string tnumber = generateExpression(*node.children[0]->children[1]);
                    //dottext.push_back("\tmove " + allocateRegisterSM() + ", " + registerS);
                    //dottext.push_back("\tsw " + registerS + ", " + to_string((stoi(id->returnType)+stoi(tnumber))*4) + "($sp)");
                    dottext.push_back("\taddi " + allocateRegister() + ", $sp, " + to_string((offset - (stoi(id->returnType))-1)*4)); //MUDEI AQ EM
                    dottext.push_back("\tmul " + tnumber + ", " + tnumber + ", 4");
                    dottext.push_back("\tsub " + allocateRegisterMM() + ", " + allocateRegisterMM() + ", " + tnumber);
                    dottext.push_back("\tsw " + registerS + ", 0(" + allocateRegisterMM() + ")");
                }
            }
    
        } else {
            generateExpression(*node.children[0]);
        }
        regCounter = 0;
        regCounterS = 0;

    } else if(node.value == "return"){
        dottext.push_back("\tmove $v0, " + generateExpression(*node.children[0]));
        dottext.push_back("\tlw $ra, " + to_string((offset-1)*4) + "($sp)");
        dottext.push_back("\tadd $sp, $sp, " + to_string(offset*4));
        dottext.push_back("\tjr $ra");

    } else {
        if(hasChildren(&node)){
            for (ASTNode* child : node.children) {
                generate(*child); 
            }
        }
    }
}
string getFirstFunction(ASTNode &node){
    if(hasChildren(&node)){
            for (ASTNode* child : node.children) {
                 if(child->value == "fun-declaracao"){
                    return treatIDNUM(child->children[1]->value);
                 }
            }
        }
};

void includeInstructions(string firstFunction){
    //Cabeçalhos
    dotdata.push_back(".data");
    dottext.push_back(".text");
    //dottext.push_back("\tjal " + firstFunction);
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

int toFile(){

    ofstream fio("output.asm", ios::app);
    if (fio.is_open()) {
        for (std::string ins: dotdata) {
            fio << ins << endl;
        }
        for (std::string ins: dottext) {
            fio << ins << endl;
        }
        fio.close();
        cout << "File closed." << endl;
        }
            else {
                cout << "Error opening file!" << endl;
            }
        return 0;
}

