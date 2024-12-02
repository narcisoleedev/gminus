## Simple lexer made in cpp for C- language.

In case you're my professor here are the names of the members:

LEXER -> *done* [STRINGSTREAM -> TOKENS]

SYNTAX ANALYSER: [TOKENS -> AST]
    - Primitive Tree: *done* [TOKENS -> PRIMITIVE TREE]
    - AST: *to be done* [PRIMITIVE TREE-> AST]

SEMANTIC ANALYSER: [<i>creates nothing actually</i>]
    - Symbol Table (we need to create the symbol table while running the AST): *to be done*
    - Debugger (with line and error type): *to be done*

CODE GENERATOR: [AST -> .asm(MIPS)]
    - Run the AST and generate the code bottom-up;

TO RUN: ```make```

ERRORS:
    - It gives an unkwown error at prg1.c-

* Guilherme Narciso Lee | nUSP: 12543203
* Guilherme Cavalanti Gomes | nUSP: 11844788