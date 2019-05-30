output: main.o randutils.o game.o word_engine.o
	g++ main.o randutils.o game.o word_engine.o -o out

main.o: main.cpp
	g++ -c main.cpp

randutils.o: randutils.cpp randutils.h
	g++ -c randutils.cpp randutils.h

game.o: game.cpp game.h
	g++ -c game.cpp game.h

word_engine.o: word_engine.cpp word_engine.h
	g++ -c word_engine.cpp word_engine.h

clean:
	rm *.o
