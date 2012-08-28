main.out main1.out : main.o test.o test1.o main1.o
	g++ -o main.out test.o test1.o main.o
	g++ -o main1.out main1.o
test.o: test.cpp
	g++ -c test.cpp -o test.o
test1.o: test1.cpp
	g++ -c test1.cpp -o test1.o
main.o: main.cpp
	g++ -c main.cpp -o main.o
main1.o: main1.cpp
	g++ -c main1.cpp -o main1.o
.PHONY:clean
clean:
	rm  *.o *.out
