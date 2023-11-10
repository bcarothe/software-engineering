tictactoe: tictactoe-v1.0.o board.o player.o
	g++ -std=c++11 tictactoe-v1.0.o board.o player.o -o tictactoe

tictactoe-v1.0.o: tictactoe-v1.0.cpp
	g++ -std=c++11 -c tictactoe-v1.0.cpp

board.o: board.cpp board.hpp
	g++ -std=c++11 -c board.cpp

player.o: player.cpp player.hpp
	g++ -std=c++11 -c player.cpp

clean:
	rm *.o tictactoe
