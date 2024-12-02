main:
	bison -d parser.y
	g++ main.cpp lexer.cpp parser.tab.c -o lexer	
	# ./lexer ./input/prg2.c- > out2.txt 2>&1
	# ./lexer ./input/prg3.c- > out3.txt 2>&1
	# ./lexer ./input/prg4.c- > out4.txt 2>&1
	# ./lexer ./input/prg5.c- > out5.txt 2>&1
	./lexer ./input/prg6.c- > out6.txt 2>&1
	# ./lexer ./input/prg7.c- > out7.txt 2>&1
	# ./lexer ./input/prg8.c- > out8.txt 2>&1
	./lexer ./input/prg9.c- > out9.txt 2>&1
	./lexer ./input/prg1.c- > out1.txt 2>&1

