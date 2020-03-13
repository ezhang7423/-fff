FLAGS=--std=c++11

main: index.cpp future.o mantra.o reflection.o
	g++ ${FLAGS} -o $^ $@

future.o: future/main.cpp
	g++ ${FLAGS} -c $^ $@

mantra.o: mantra/main.cpp
	g++ ${FLAGS} -c $^ $@

reflection.o: reflection/main.cpp
	g++ ${FLAGS} -c $^ $@


clean:
	rm -rf *.o main