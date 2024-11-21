%{
    #include <cstdio>
    #include <cstdlib>

    int yylex();
    int yylineo();
    void yyerror(const char *s) {
        fprintf(stderr, "Error at line %i: %s\n",yylineo(), s);
    }
%}

%token NUMBER 
%token RELOP
%token INT VOID 
%token IF ELSE RETURN WHILE ID FOR
%token PLUS MINUS TIMES DIV PV COMMA OP CP OB CB OCB CCB EQUAL VEJODEPOIS
%token ERROR
%token YYEOF

%%

programa:
    declaracao-lista YYEOF{ printf("Parsed a programa\n"); }

declaracao-lista:
    declaracao-lista declaracao { printf("Parsed a declaracao-lista\n"); } |
    declaracao { printf("Parsed a declaracao-lista\n"); }

declaracao:
    var-declaracao { printf("Parsed a declaracao\n"); } |
    fun-declaracao { printf("Parsed a declaracao\n"); }

var-declaracao:
    tipo-especificador ID PV {  printf("Parsed a var-declaracao\n"); } |
    tipo-especificador ID OB NUMBER CB PV { printf("Parsed a var-declaracao \n");}

tipo-especificador:
    INT { printf("Parsed a tipo-especificador \n") ;} |
    VOID { printf("Parsed a tipo-especificador\n"); } |
    error

fun-declaracao:
    tipo-especificador ID OP params CP composto-decl { printf("Parsed a fun-declaracao\n"); }

params:
    params-lista { printf("Parsed a params\n"); } |
    VOID { printf("Parsed a params\n"); }

params-lista:
    params-lista COMMA param { printf("Parsed a params-lista\n"); } |
    param { printf("Parsed a params-lista\n"); }

param:
    tipo-especificador ID { printf("Parsed a param\n"); } |
    tipo-especificador ID OB CB { printf("Parsed a param\n"); }

composto-decl:
    OCB local-declaracoes statement-lista CCB { printf("Parsed a composto-decl\n"); }

local-declaracoes:
    local-declaracoes var-declaracao { printf("Parsed a local-declaracoes\n"); } |
    | /* empty */ { /* This is the base case for recursion */ }

statement-lista:
    statement-lista statement { printf("Parsed a statement-lista\n"); } |
    | /* empty */ { /* This is the base case for recursion */ }

statement:
    expressao-decl { printf("Parsed a statement\n"); } |
    composto-decl { printf("Parsed a statement\n"); } |
    selecao-decl { printf("Parsed a statement\n"); } |
    iteracao-decl { printf("Parsed a statement\n"); } |
    retorno-decl { printf("Parsed a statement\n"); } |

expressao-decl:
    expressao PV { printf("Parsed a expressao-decl\n"); } |
    PV { printf("Parsed a expressao-decl\n"); }

selecao-decl:
    IF OP expressao CP statement { printf("Parsed a selecao-decl\n"); } |
    IF OP expressao CP statement ELSE statement { printf("Parsed a selecao-decl\n"); }

iteracao-decl:
    WHILE OP expressao CP statement { printf("Parsed a iteracao-decl\n"); }

retorno-decl:
    RETURN PV { printf("Parsed a retorno-decl\n"); } |
    RETURN expressao { printf("Parsed a retorno-decl\n"); }

expressao:
    var EQUAL expressao { printf("Parsed a expressao\n"); } |
    simples-expressao { printf("Parsed a expressao\n"); }

var:
    ID { printf("Parsed a var\n"); } |
    ID OB expressao CB { printf("Parsed a var\n"); }

simples-expressao:
    soma-expressao RELOP soma-expressao { printf("Parsed a simplex-exmpressao\n"); } |
    soma-expressao { printf("Parsed a simples-expressao\n"); } |
    error

soma-expressao:
    soma-expressao soma termo { printf("Parsed a soma-expressao\n"); } |
    termo { printf("Parsed a soma-expressao\n"); }

soma:
    PLUS { printf("Parsed a soma\n"); } |
    MINUS { printf("Parsed a subtracao\n"); }

termo:
    termo mult fator { printf("Parsed a termo\n"); } |
    fator { printf("Parsed a termo\n"); }

mult:
    TIMES { printf("Parsed a mult\n"); } |
    DIV { printf("Parsed a div\n"); }

fator:
    OP expressao CP { printf("Parsed a fator\n"); } |
    var { printf("Parsed a fator\n"); } |
    ativacao { printf("Parsed a fator\n"); } |
    NUMBER { printf("Parsed a fator\n"); } 

ativacao:
    ID OP args CP { printf("Parsed a ativacao\n"); }

args:
    arg-lista { printf("Parsed a args\n"); }
    | /* empty */ { /* This is the base case for recursion */ }
arg-lista: 
    arg-lista COMMA expressao { printf("Parsed a arg-lista\n"); } |
    expressao { printf("Parsed a arg-lista\n"); }
%%

