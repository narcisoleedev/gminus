## Simple compiler made in cpp for C- language.

In case you're my professor here are the names of the members:

* Guilherme Narciso Lee | nUSP: 12543203
* Guilherme Cavalanti Gomes | nUSP: 11844788
* Carlos Eduardo Bertoni Pompermayer | nUSP: 11795742

### Steps:

<b>LEXER</b> -> *done* [STRINGSTREAM -> TOKENS]

<b>SYNTAX ANALYSER:</b> [TOKENS -> AST]
    - Primitive Tree: *done* [TOKENS -> PRIMITIVE TREE]
    - AST: *done* [PRIMITIVE TREE-> AST]

<b>SEMANTIC ANALYSER:</b> [<i>creates nothing actually</i>]
    - Symbol Table (we need to create the symbol table while running the AST): *done*
    - Debugger (with line and error type): *done* //It does not get the line but gets the type

<b>CODE GENERATOR:</b> [AST -> output.asm(MIPS)] progress: 90%
    - Run the AST and generate the code bottom-up;

TO RUN: ```make```

It creates the <b>"parser.tab.c"</b> and <b>"parser.tab.h"</b> and run all files in the "input" folder.
The debugging with all steps (lexer, syntax and semantic) are outputed in the out files.
After running all, the last execution will run an <b>"output.asm"</b> file at the root of the project folder that you can run on Mars.

TO RUN A SIMPLE FILE: 

./gminus x > y 2>&1
x: input file path
y: output (debug) file path

ERRORS:
    - It does not run array as arguments (planned but not done in the given time)
    - It saves all results of function calls in $v0 register, which can cause problem in some circustances, when calling more than one function at the same time.
    - And some others.


