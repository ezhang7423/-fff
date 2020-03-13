FLAGS=--std=c++11

main: index.cpp future.o mantra.o reflection.o
	g++ -pthread ${FLAGS} -o $@ $^ && ./main

future.o: future/main.cpp
	g++ ${FLAGS} -c $^ -o $@

mantra.o: mantra/main.cpp
	g++ ${FLAGS} -c $^ -o $@

reflection.o: reflection/main.cpp
	g++ ${FLAGS} -c $^ -o $@

clean:
	rm -rf *.o main