%{
#include <cstdio>
#include <cstdlib>

// Declare yylex so Bison can find it.
int yylex();
void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
%}

%token ID SYMBOL NUMBER KEYWORD RELOP

%%
expr:
    SYMBOL expr_tail { printf("Parsed a SYMBOL\n"); }
    | NUMBER expr_tail { printf("Parsed a NUMBER\n"); }
    | ID expr_tail { printf("Parsed an ID\n"); }
    | KEYWORD expr_tail { printf("Parsed a KEYWORD\n"); }
    | RELOP expr_tail { printf("Parsed a RELOP\n"); }
    | YYEOF { printf("Parsed an EOF\n"); }
    ;

expr_tail:
    expr { /* continue parsing */ }
    // | /* empty */ { /* end of expression */ }
    ;
%%

