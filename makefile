blpsecure: main.o obj.o RM.o sub.o
	g++ -o blpsecure obj.o main.o RM.o sub.o

main.o: main.cpp RM.h
	g++ -c -g -std=c++11 -Wall  main.cpp

obj.o: obj.cpp obj.h
	g++ -c -g -std=c++11 -Wall  obj.cpp

RM.o: RM.cpp obj.h RM.h sub.h
	g++ -c -g -std=c++11 -Wall  RM.cpp

sub.o: sub.cpp sub.h
	g++ -c -g -std=c++11 -Wall sub.cpp

clean:
	rm *.o blpsecure