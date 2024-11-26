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
        // Indentar com base no nível
        for (int i = 0; i < level; i++) cout << "  ";
        cout << n->value << endl;

        //Recursivamente exibir os filhos
        for (ASTNode* child : n->children) {
            if (child) printNode(level + 1, child);
        }
    }
    void printTree() {
        printNode(0, root);
    }
};