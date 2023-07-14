main_print: main.o FileMaker.o Hash.o 
	g++ -Wall -o $@ $^

main.o: main.cpp
	g++ -Wall -c $^

FileMaker.o: FileMaker.cpp 
	g++ -Wall -c $^

Hash.o: Hash.cpp 
	g++ -Wall -c $^


clean:
	rm -f *.o main_print