%{
    #include <cstdio>
    #include <cstdlib>
    #include <string.h>
    #include <malloc.h>

    int yylex();
    int yylineo();
    void yyerror(const char *s) {
        fprintf(stderr, "Error at line %i: %s\n",yylineo(), s);
    }
%}
%code requires {
    #ifndef __AST_HPP_INCLUDED__
    #define __AST_HPP_INCLUDED__
    #include "ast.hpp"
    #endif
}
%code {
    ASTNode* r;
    void getRoot(ASTNode* root){
        r = root;
    }
    AST* yytree(){
        AST* ast = new AST(r);
        ast->transformToAST();
        return ast; 
    }
}

%union {
    ASTNode* ast;
    int intval;
    char* strval;
}

%token <intval> NUMBER
%token <strval> ID
%token <strval> RELOP
%token INT VOID 
%token IF ELSE RETURN WHILE FOR
%token PLUS MINUS TIMES DIV PV COMMA OP CP OB CB OCB CCB EQUAL VEJODEPOIS
%token ERROR
%token YYEOF

%type <ast> programa declaracao-lista declaracao var-declaracao fun-declaracao tipo-especificador params params-lista param composto-decl local-declaracoes statement-lista 
%type <ast> expressao-decl selecao-decl iteracao-decl retorno-decl expressao var simples-expressao soma-expressao soma termo fator mult ativacao args arg-lista statement
%type <name> INT OB CB VOID

%%

programa:   
    declaracao-lista YYEOF{ 
        $$ = new ASTNode("programa");
        $$->insertChildren($1);
        getRoot($$);
    }

declaracao-lista:
    declaracao-lista declaracao { 
        //printf("Parsed a declaracao-lista com 2\n"); 
        $$ = new ASTNode("declaracao-lista");
        $$->insertChildren($1);
        $$->insertChildren($2);
        } |
    declaracao { 
        //printf("Parsed a declaracao-listacom 1\n"); 
        $$ = new ASTNode("declaracao-lista");
        $$->insertChildren($1);
        } 

declaracao:
    var-declaracao { 
        //printf("Parsed a declaracao\n"); 
        $$ = new ASTNode("declaracao");
        $$->insertChildren($1);
        } |
    fun-declaracao { 
        //printf("Parsed a declaracao\n"); 
        $$ = new ASTNode("declaracao");
        $$->insertChildren($1);
    }

var-declaracao:
    tipo-especificador ID PV { 
        //printf("Parsed a var-declaracao\n"); 
        $$ = new ASTNode("var-declaracao");
        $$->insertChildren($1);
        char* id = (char*) malloc(sizeof(char)*50);
        sprintf(id, "ID(%s)", $2);
        $$->insertChildren(new ASTNode(id));
        free(id);
    } |
    tipo-especificador ID OB NUMBER CB PV { 
        //printf("Parsed a var-declaracao\n"); 
        $$ = new ASTNode("var-declaracao");
        $$->insertChildren($1);
        char* id = (char*) malloc(sizeof(char)*50);
        sprintf(id, "ID(%s)", $2);
        $$->insertChildren(new ASTNode(id));
        free(id);
        $$->insertChildren(new ASTNode("OB"));
        char* number = (char*) malloc(sizeof(char)*20);
        sprintf(number, "NUM(%d)", $4);
        $$->insertChildren(new ASTNode(number));
        $$->insertChildren(new ASTNode("CB"));
    } 

tipo-especificador:
    INT { 
        //printf("Parsed a tipo-especificador \n") ;
        $$ = new ASTNode("tipo-especificador");
        $$->insertChildren(new ASTNode("int"));
    } |
    VOID { 
        //printf("Parsed a tipo-especificador \n") ;
        $$ = new ASTNode("tipo-especificador");
        $$->insertChildren(new ASTNode("void"));
    } // |
    // error

fun-declaracao:
    tipo-especificador ID OP params CP composto-decl { 
        //printf("Parsed a fun-declaracao\n"); 
        $$ = new ASTNode("fun-declaracao");
        $$->insertChildren($1);
        char* id = (char*) malloc(sizeof(char)*50);
        sprintf(id, "ID(%s)", $2);
        $$->insertChildren(new ASTNode(id));
        free(id);
        $$->insertChildren(new ASTNode("OP"));
        $$->insertChildren($4);
        $$->insertChildren(new ASTNode("CP"));
        $$->insertChildren($6);
    }

params:
    params-lista { 
        //printf("Parsed a params\n"); 
        $$ = new ASTNode("params");
        $$->insertChildren($1);
    } |
    VOID { 
        //printf("Parsed a params\n"); 
        $$ = new ASTNode("params");
        $$->insertChildren(new ASTNode("void"));
        }

params-lista:
    params-lista COMMA param { 
        //printf("Parsed a params-lista\n"); 
        $$ = new ASTNode("params-lista");
        $$->insertChildren($1);
        $$->insertChildren(new ASTNode("COMMA"));
        $$->insertChildren($3);
    } |
    param { 
        //printf("Parsed a params-lista\n"); 
        $$ = new ASTNode("params-lista");
        $$->insertChildren($1);
    }

param:
    tipo-especificador ID { 
        //printf("Parsed a param\n"); 
        $$ = new ASTNode("param");
        $$->insertChildren($1);
        char* id = (char*) malloc(sizeof(char)*50);
        sprintf(id, "ID(%s)", $2);
        $$->insertChildren(new ASTNode(id));
        free(id);
    } |
    tipo-especificador ID OB CB { 
        //printf("Parsed a param\n"); 
        $$ = new ASTNode("param");
        $$->insertChildren($1);
        char* id = (char*) malloc(sizeof(char)*50);
        sprintf(id, "ID(%s)", $2);
        $$->insertChildren(new ASTNode(id));
        free(id);
        $$->insertChildren(new ASTNode("OB"));
        $$->insertChildren(new ASTNode("CB"));
        $$->insertChildren(new ASTNode("vector"));
    }

composto-decl:
    OCB local-declaracoes statement-lista CCB { 
        //printf("Parsed a composto-decl\n"); 
        $$ = new ASTNode("composto-decl");
        $$->insertChildren(new ASTNode("OCB"));
        $$->insertChildren($2);
        $$->insertChildren($3);
        $$->insertChildren(new ASTNode("CCB"));
    }

local-declaracoes:
    local-declaracoes var-declaracao { 
        //printf("Parsed a local-declaracoes\n"); 
        $$ = new ASTNode("local-declaracoes");
        $$->insertChildren($1);
        $$->insertChildren($2);    
    }
    | /* empty */ {         
        //printf("Parsed a local-declaracoes\n"); 
        $$ = new ASTNode("local-declaracoes");
    }

statement-lista:
    statement-lista statement { 
        //printf("Parsed a statement-lista\n"); 
        $$ = new ASTNode("statement-lista");
        $$->insertChildren($1);
        $$->insertChildren($2);  
    }
    | /* empty */ { 
        //printf("Parsed a statement-lista\n"); 
        $$ = new ASTNode("statement-lista");
     }

statement:
    expressao-decl { 
        //printf("Parsed a statement\n"); 
        $$ = new ASTNode("statement");
        $$->insertChildren($1);
    } |
    composto-decl { 
        //printf("Parsed a statement\n"); 
        $$ = new ASTNode("statement");
        $$->insertChildren($1);
    } |
    selecao-decl { 
        //printf("Parsed a statement\n"); 
        $$ = new ASTNode("statement");
        $$->insertChildren($1);
    } |
    iteracao-decl { 
        //printf("Parsed a statement\n"); 
        $$ = new ASTNode("statement");
        $$->insertChildren($1);
    } |
    retorno-decl { 
        //printf("Parsed a statement\n"); 
        $$ = new ASTNode("statement");
        $$->insertChildren($1);
    }

expressao-decl:
    expressao PV { 
        //printf("Parsed a expressao-decl\n"); 
        $$ = new ASTNode("expressao-decl");
        $$->insertChildren($1);
    } |
    PV { 
        //printf("Parsed a expressao-decl\n"); 
        $$ = new ASTNode("expressao-decl");
    };

selecao-decl:
    IF OP expressao CP statement { 
        //printf("Parsed a selecao-decl\n"); 
        $$ = new ASTNode("selecao-decl");
        $$->insertChildren(new ASTNode("IF"));
        $$->insertChildren(new ASTNode("OP"));
        $$->insertChildren($3);
        $$->insertChildren(new ASTNode("CP"));
        $$->insertChildren($5);
    } |
    IF OP expressao CP statement ELSE statement { 
        //printf("Parsed a selecao-decl\n"); 
        $$ = new ASTNode("selecao-decl");
        $$->insertChildren(new ASTNode("IF"));
        $$->insertChildren(new ASTNode("OP"));
        $$->insertChildren($3);
        $$->insertChildren(new ASTNode("CP"));
        $$->insertChildren($5);
        $$->insertChildren(new ASTNode("ELSE"));
        $$->insertChildren($7);
    }

iteracao-decl:
    WHILE OP expressao CP statement { 
        //printf("Parsed a iteracao-decl\n"); 
        $$ = new ASTNode("iteracao-decl");
        $$->insertChildren(new ASTNode("WHILE"));
        $$->insertChildren(new ASTNode("OP"));
        $$->insertChildren($3);
        $$->insertChildren(new ASTNode("CP"));
        $$->insertChildren($5);
    }

retorno-decl:
    RETURN PV { 
        //printf("Parsed a retorno-decl\n"); 
        $$ = new ASTNode("retorno-decl");
        $$->insertChildren(new ASTNode("RETURN"));
    } |
    RETURN expressao { 
        //printf("Parsed a retorno-decl\n"); 
        $$ = new ASTNode("retorno-decl");
        $$->insertChildren(new ASTNode("RETURN"));
        $$->insertChildren($2);
    } 

expressao:
    var EQUAL expressao { 
        //printf("Parsed a expressao\n"); 
        $$ = new ASTNode("expressao");
        $$->insertChildren($1);
        $$->insertChildren(new ASTNode("EQUAL"));
        $$->insertChildren($3);    
    } |
    simples-expressao { 
        //printf("Parsed a expressao\n"); 
        $$ = new ASTNode("expressao");
        $$->insertChildren($1);
    }

var:
    ID { 
        //printf("Parsed a var\n"); 
        $$ = new ASTNode("var");
        char* id = (char*) malloc(sizeof(char)*50);
        sprintf(id, "ID(%s)", $1);
        $$->insertChildren(new ASTNode(id));
        free(id); 
    } |
    ID OB expressao CB { 
        //printf("Parsed a var\n"); 
        $$ = new ASTNode("var");
        char* id = (char*) malloc(sizeof(char)*50);
        sprintf(id, "ID(%s)", $1);
        $$->insertChildren(new ASTNode(id));
        free(id);    
        $$->insertChildren(new ASTNode("OB"));
        $$->insertChildren($3); 
        $$->insertChildren(new ASTNode("CB"));  
    }

simples-expressao:
    soma-expressao RELOP soma-expressao { 
        //printf("Parsed a simplex-exmpressao\n"); 
        $$ = new ASTNode("simples-expressao");
        $$->insertChildren($1);
        char* relop = (char*) malloc(sizeof(char) * 10);
        sprintf(relop, "%s", $2);
        $$->insertChildren(new ASTNode(relop));
        free(relop); 
        $$->insertChildren($3);
    } |
    soma-expressao { 
        //printf("Parsed a simplex-exmpressao\n"); 
        $$ = new ASTNode("simples-expressao");
        $$->insertChildren($1);
    } |
    error

soma-expressao:
    soma-expressao soma termo { 
        //printf("Parsed a soma-expressao\n"); 
        $$ = new ASTNode("soma-expressao");
        $$->insertChildren($1);
        $$->insertChildren($2);
        $$->insertChildren($3);
    } |
    termo { 
        //printf("Parsed a soma-expressao\n"); 
        $$ = new ASTNode("soma-expressao");
        $$->insertChildren($1);
    }

soma:
    PLUS { 
        //printf("Parsed a soma\n"); 
        $$ = new ASTNode("soma");
        $$->insertChildren(new ASTNode("PLUS"));    
    } |
    MINUS { 
        //printf("Parsed a soma\n"); 
        $$ = new ASTNode("soma");
        $$->insertChildren(new ASTNode("MINUS"));    
    }

termo:
    termo mult fator { 
        //printf("Parsed a termo\n"); 
        $$ = new ASTNode("termo");
        $$->insertChildren($1);
        $$->insertChildren($2);
        $$->insertChildren($3);
    } |
    fator { 
        //printf("Parsed a termo\n"); 
        $$ = new ASTNode("termo");
        $$->insertChildren($1);
    }

mult:
    TIMES { 
        //printf("Parsed a mult\n"); 
        $$ = new ASTNode("mult");
        $$->insertChildren(new ASTNode("TIMES"));    
    } |
    DIV { 
        //printf("Parsed a div\n"); 
        $$ = new ASTNode("div");
        $$->insertChildren(new ASTNode("DIV"));    
    }

fator:
    OP expressao CP { 
        //printf("Parsed a fator\n"); 
        $$ = new ASTNode("fator");
        $$->insertChildren(new ASTNode("OP"));
        $$->insertChildren($2);
        $$->insertChildren(new ASTNode("CP"));
    } |
    var { 
        //printf("Parsed a fator\n"); 
        $$ = new ASTNode("fator");
        $$->insertChildren($1);
    } |
    ativacao { 
        //printf("Parsed a fator\n"); 
        $$ = new ASTNode("fator");
        $$->insertChildren($1);
    }  |
    NUMBER { 
        //printf("Parsed a fator\n"); 
        $$ = new ASTNode("fator");
        char* number = (char*) malloc(sizeof(char)*20);
        sprintf(number, "NUM(%d)", $1);
        $$->insertChildren(new ASTNode(number));
    }  

ativacao:
    ID OP args CP { 
        //printf("Parsed a ativacao\n"); 
        $$ = new ASTNode("ativacao");
        char* id = (char*) malloc(sizeof(char)*50);
        sprintf(id, "ID(%s)", $1);
        $$->insertChildren(new ASTNode(id));
        free(id);
        $$->insertChildren(new ASTNode("OP"));
        $$->insertChildren($3);
        $$->insertChildren(new ASTNode("CP"));    
    }

args:
    arg-lista { 
        //printf("Parsed a args\n"); 
        $$ = new ASTNode("args");
        $$->insertChildren($1);
    }
    | /* empty */ { 
        //printf("Parsed a args\n"); 
        $$ = new ASTNode("args");
     }
arg-lista: 
    arg-lista COMMA expressao { 
        //printf("Parsed a arg-lista\n"); 
        $$ = new ASTNode("arg-lista");
        $$->insertChildren($1);
        $$->insertChildren(new ASTNode("COMMA"));
        $$->insertChildren($3);
    } |
    expressao { 
        //printf("Parsed a arg-lista\n"); 
        $$ = new ASTNode("arg-lista");
        $$->insertChildren($1);
    }
%%

