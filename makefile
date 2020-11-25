.PHONY:
	all clean
all:
	bison -o parser.cpp -v parser.y
	flex -o lexer.cpp lexer.l
	g++ -o main lexer.cpp parser.cpp symbol.cpp tree.cpp -std=c++11
clean:
	rm main parser.cpp parser.hpp lexer.cpp lexer.hpp 
