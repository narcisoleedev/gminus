#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class CodeGenerator {
public:
    int regCounter;
    vector<string> instructions;
    unordered_map<string, int> symbolTable;

    CodeGenerator() : regCounter(0) {}

    string allocateRegister() {
        return "$t" + to_string(regCounter++);
    }

    void deallocateRegister() {
        regCounter--;
    }

    void generate(ASTNode* node) {
        if (node->value == "programa") {
            for (ASTNode* child : node->children) {
                generate(child);
            }
        } else if (node->value == "fun-declaracao") {
            string funcName = node->children[1]->value;
            instructions.push_back(funcName + ":");
            generate(node->children[3]);  // Processar corpo da função
        } else if (node->value == "if") {
            string labelElse = generateLabel("else");
            string labelEnd = generateLabel("endif");

            // Processar condição
            string conditionReg = generateExpression(node->children[0]);
            instructions.push_back("beqz " + conditionReg + ", " + labelElse);
            deallocateRegister();

            // Gerar código para o bloco `if`
            generate(node->children[1]);
            instructions.push_back("j " + labelEnd);

            // Gerar código para o bloco `else`, se houver
            instructions.push_back(labelElse + ":");
            if (node->children.size() > 2) {
                generate(node->children[2]);
            }
            instructions.push_back(labelEnd + ":");
        } else if (node->value == "while") {
            string labelStart = generateLabel("while");
            string labelEnd = generateLabel("endwhile");

            // Gerar condição
            instructions.push_back(labelStart + ":");
            string conditionReg = generateExpression(node->children[0]);
            instructions.push_back("beqz " + conditionReg + ", " + labelEnd);
            deallocateRegister();

            // Corpo do while
            generate(node->children[1]);
            instructions.push_back("j " + labelStart);
            instructions.push_back(labelEnd + ":");
        } else if (node->value == "return") {
            string valueReg = generateExpression(node->children[0]);
            instructions.push_back("move $v0, " + valueReg);
            instructions.push_back("jr $ra");
            deallocateRegister();
        } else if (node->value == "EQUAL") {
            string varName = node->children[0]->children[0]->value;
            string valueReg = generateExpression(node->children[1]);
            instructions.push_back("sw " + valueReg + ", " + varName);
            deallocateRegister();
        } else {
            for (ASTNode* child : node->children) {
                generate(child);
            }
        }
    }

    string generateExpression(ASTNode* node) {
        if (node->value == "NUM") {
            string reg = allocateRegister();
            instructions.push_back("li " + reg + ", " + node->children[0]->value);
            return reg;
        } else if (node->value == "PLUS") {
            string leftReg = generateExpression(node->children[0]);
            string rightReg = generateExpression(node->children[1]);
            string resultReg = allocateRegister();
            instructions.push_back("add " + resultReg + ", " + leftReg + ", " + rightReg);
            deallocateRegister();
            deallocateRegister();
            return resultReg;
        } else if (node->value == "TIMES") {
            string leftReg = generateExpression(node->children[0]);
            string rightReg = generateExpression(node->children[1]);
            string resultReg = allocateRegister();
            instructions.push_back("mul " + resultReg + ", " + leftReg + ", " + rightReg);
            deallocateRegister();
            deallocateRegister();
            return resultReg;
        }
        return "";
    }

    string generateLabel(const string& base) {
        static int labelCounter = 0;
        return base + to_string(labelCounter++);
    }

    void printInstructions() {
        for (const string& instr : instructions) {
            cout << instr << endl;
        }
    }
};
