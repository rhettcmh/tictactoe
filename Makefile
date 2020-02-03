run: game1
	./game1

game1: main.o board.o game.o player.o human.o ai.o aiOverwatch.o
	g++ main.o board.o game.o player.o human.o ai.o aiOverwatch.o -o game1

main.o: main.cpp
	g++ -Wall -c main.cpp

board.o: board.cpp board.h
	g++ -Wall -c board.cpp

game.o: game.cpp game.h
	g++ -Wall -c game.cpp

player.o: player.cpp player.h
	g++ -Wall -c player.cpp

human.o: human.cpp human.h
	g++ -Wall -c human.cpp

ai.o: ai.cpp ai.h
	g++ -Wall -c ai.cpp

aiOverwatch.o: aiOverwatch.cpp aiOverwatch.h
	g++ -Wall -c aiOverwatch.cpp

clean:
	rm *.o game1