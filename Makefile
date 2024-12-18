main:
	bison -d src/parser.y
	g++ main.cpp src/lexer.cpp parser.tab.c src/semantics.cpp -o gminus	
	#./gminus ./input/prg1.c- > output/out1.txt 2>&1
	#./gminus ./input/prg2.c- > output/out2.txt 2>&1
	#./gminus ./input/prg3.c- > output/out3.txt 2>&1
	#./gminus ./input/prg4.c- > output/out4.txt 2>&1
	#./gminus ./input/prg5.c- > output/out5.txt 2>&1
	#./gminus ./input/prg6.c- > output/out6.txt 2>&1
	#./gminus ./input/prg7.c- > output/out7.txt 2>&1
	#./gminus ./input/prg8.c- > output/out8.txt 2>&1
	#./gminus ./input/prg9.c- > output/out9.txt 2>&1
	./gminus ./input/prg10.c- > output/out10.txt 2>&1
	

