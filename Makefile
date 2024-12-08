main:
	bison -d parser.y
	g++ main.cpp lexer.cpp parser.tab.c -o lexer	
	#./lexer ./input/prg1.c- > output/out1.txt 2>&1
	#./lexer ./input/prg2.c- > output/out2.txt 2>&1
	#./lexer ./input/prg3.c- > output/out3.txt 2>&1
	#./lexer ./input/prg4.c- > output/out4.txt 2>&1
	#./lexer ./input/prg5.c- > output/out5.txt 2>&1
	#./lexer ./input/prg6.c- > output/out6.txt 2>&1
	#./lexer ./input/prg7.c- > output/out7.txt 2>&1
	#./lexer ./input/prg8.c- > output/out8.txt 2>&1
	./lexer ./input/prg9.c- > output/out9.txt 2>&1
	./lexer ./input/prg10.c- > output/out10.txt 2>&1
	

