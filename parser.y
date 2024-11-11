%{
    #include <cstdio>
    #include <cstdlib>

    int yylex();
    void yyerror(const char *s) {
        fprintf(stderr, "Error: %s\n", s);
}
%}

%token NUMBER 
%token RELOP
%token INT VOID 
%token IF ELSE RETURN WHILE ID
%token PLUS MINUS TIMES DIV PV COMMA OP CP OB CB OCB CCB VEJODEPOIS
%token YYEOF

%%
expr: 
    NUMBER expr_tail { printf("Parsed a NUMBER\n"); }
    | RELOP expr_tail { printf("Parsed a RELOP\n"); }
    | INT expr_tail { printf("Parsed an INT\n"); }
    | VOID expr_tail { printf("Parsed a VOID\n"); }
    | IF expr_tail { printf("Parsed an IF\n"); }
    | ELSE expr_tail { printf("Parsed an ELSE\n"); }
    | RETURN expr_tail { printf("Parsed a RETURN\n"); }
    | WHILE expr_tail { printf("Parsed a WHILE\n"); }
    | ID expr_tail { printf("Parsed an ID\n"); }
    | PLUS expr_tail { printf("Parsed a PLUS\n"); }
    | MINUS expr_tail { printf("Parsed a MINUS\n"); }
    | TIMES expr_tail { printf("Parsed a TIMES\n"); }
    | DIV expr_tail { printf("Parsed a DIV\n"); }
    | PV expr_tail { printf("Parsed a PV (semicolon)\n"); }
    | COMMA expr_tail { printf("Parsed a COMMA\n"); }
    | OP expr_tail { printf("Parsed an OP (open parenthesis)\n"); }
    | CP expr_tail { printf("Parsed a CP (close parenthesis)\n"); }
    | OB expr_tail { printf("Parsed an OB (open bracket)\n"); }
    | CB expr_tail { printf("Parsed a CB (close bracket)\n"); }
    | OCB expr_tail { printf("Parsed an OCB (open curly brace)\n"); }
    | CCB expr_tail { printf("Parsed a CCB (close curly brace)\n"); }
    | VEJODEPOIS expr_tail { printf("Parsed a VEJODEPOIS\n"); }
    | YYEOF { printf("Parsed an EOF\n"); }
    | /* empty */ { /* This is the base case for recursion */ }
    ;

expr_tail:
    expr { /* continue parsing */ }
    // | /* empty */ { /* end of expression */ }
    ;

%%

