output: main.o randutils.o
	g++ main.o randutils.o -o out

main.o: main.cpp
	g++ -c main.cpp

randutils.o: randutils.cpp randutils.h
	g++ -c randutils.cpp randutils.h

clean:
	rm *.o
