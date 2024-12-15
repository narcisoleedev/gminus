#pragma once

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class ASTNode{

    public:
        string value;
        vector<ASTNode*> children;
    ASTNode(string value){
        this->value = value;
    }
    void insertChildren(ASTNode* child){
        children.push_back(child);
    }
};

class AST{
    public:
        ASTNode* root;

    AST (ASTNode* root){
        this->root = root;
    }

    void printNode(int level, ASTNode* n) {
        for (int i = 0; i < level; i++) cout << "  "; 
                cout << n->value << endl;
        for (ASTNode* child : n->children) {
            if (child) printNode(level + 1, child);
        }
    }
    void printTree() {
        printNode(0, root);
    }
    void generateAST(ASTNode* n) {
        string v = n->value;
        //std::cout << "Nó atual: " << v << std::endl;
        // Tirar o primeiro declaracao-lista
        if(v == "programa") {
            //Eliminar declaracao-lista
            generateAST(n->children[0]);
            n->children = n->children[0]->children;
            return;
        }
        //Trocar o decl pelo tipo da expressão (if, while ou return)
        if(v == "retorno-decl") {
            n->children.erase(n->children.begin() + 0);
            n->value = "return";
        }
        if(v == "selecao-decl") {
            n->children.erase(n->children.begin() + 0);
            n->value = "if";
        }
        if(v == "iteracao-decl") {
            n->children.erase(n->children.begin() + 0);
            n->value ="while";
        }
        //Trocar simples-expressao quando é um relop
        if(v == "simples-expressao" && size(n->children)==3){
            n->value = n->children[1]->value;
            n->children.erase(n->children.begin() + 1);
        }
        //Iterar os nós da árvore
        int childIndex = 0;
        for (childIndex; childIndex < size(n->children);){
            ASTNode* node = n->children[childIndex];
            // Esse If é pra tirar nós com filhos e colocar os filhos no lugar dele
            if (
                node->value == "declaracao-lista" || node->value=="declaracao" || node->value=="params-lista" || 
                node->value=="local-declaracoes" || node->value=="statement-lista" || node->value=="expressao-decl" || 
                (node->value=="termo" && size(node->children) != 3) || node->value=="fator" || node->value=="arg-lista" ||
                (node->value == "simples-expressao" && size(node->children) != 3) || node->value=="soma" || node->value=="mult"
                ) {
                n->children.erase(n->children.begin() + childIndex);
                n->children.insert(n->children.begin() + childIndex, node->children.begin(), node->children.end());
                delete(node);
                continue;
            }
            // Esse if é pra remover folhas desnecessárias da árvore
            if(
                node->value == "OP" || node->value == "CP" || node->value == "OCB" || node->value == "CCB" || node->value == "OB" || 
                node->value == "CB" || node->value == "COMMA" || node->value == "ELSE"
                ) {
                n->children.erase(n->children.begin() + childIndex);
                delete(node);
                continue;
            }
            if(node->value == "tipo-especificador") {
                n->children.erase(n->children.begin() + childIndex);
                n->children.insert(n->children.begin() + childIndex, node->children.begin(), node->children.end());
                childIndex++;
                continue;
            }
            if(childIndex < size(n->children)) generateAST(n->children[childIndex]);
            childIndex++;
        }
    }
    //Conserta o soma-expressao e o statement/args
    void fixArvore(ASTNode* n){

        //Pegar expressao ternaria e colocar o operador no lugar e deixa-la binaria
        if(n->value == "soma-expressao" || n->value == "termo"){
            if(size(n->children)==3){
                n->value = n->children[1]->value;
                delete(n->children[1]);
                n->children.erase(n->children.begin() + 1);
            }   
        }
        int childIndex = 0;
        for(childIndex; childIndex < size(n->children);){
            ASTNode* child = n->children[childIndex];

            //Tirar soma-expressao com 1 filho da árvore
            if (child->value=="soma-expressao" && size(child->children) == 1) {
                n->children.erase(n->children.begin() + childIndex);
                n->children.insert(n->children.begin() + childIndex, child->children.begin(), child->children.end());   
                delete(child);
            }
            
            //Tirar statements/args vazios 
            if ((child->value=="statement" || child->value=="args") && size(child->children) == 0) {
                n->children.erase(n->children.begin() + childIndex);
                delete(child);
                continue;
            }
            fixArvore(n->children[childIndex]);
            if(childIndex < size(n->children)) childIndex++;
        }
    }
    void transformToAST() {
        generateAST(root);
        fixArvore(root);
    }
};