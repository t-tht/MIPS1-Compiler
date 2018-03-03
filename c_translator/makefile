CPPFLAGS += -std=c++11 -W -Wall -g -Wno-unused-parameter
CPPFLAGS += -I include

all : bin/c_compiler

src/c_parser.tab.cpp src/c_parser.tab.hpp : src/c_parser.y
	bison -v -d src/c_parser.y -o src/c_parser.tab.cpp

src/c_lexer.yy.cpp : src/c_lexer.flex src/c_parser.tab.hpp
	flex -o src/c_lexer.yy.cpp  src/c_lexer.flex

<<<<<<< HEAD
bin/c_compiler : src/c_compiler.o src/c_parser.tab.o src/c_lexer.yy.o src/c_parser.tab.o 
=======
bin/c_compiler : src/c_compiler.o src/c_parser.tab.o src/c_lexer.yy.o src/c_parser.tab.o
>>>>>>> 845e06f0b6fa29db33583861a6d5fa93b19ee5d2
	mkdir -p bin
	g++ $(CPPFLAGS) -o bin/c_compiler $^


clean :
	rm src/*.o
	rm bin/*
	rm src/*.tab.cpp
	rm src/*.yy.cpp
	rm src/*.output
