# executable files for this directory
TARGET=person/person_test.out X_and_Y/X_and_Y_test.out\
			 mutable_test.out Screen/screen_test.out 
OBJ = person/person.o X_and_Y/X_and_Y_test.o\
		 	mutable_test.o Screen/Screen.o 
$(TARGET): $(OBJ)
	g++ -o person/person_test.out person/person.o person/person_test.cpp
	g++ -o X_and_Y/X_and_Y_test.out X_and_Y/X_and_Y_test.o
	g++ -o mutable_test.out mutable_test.o
	g++ -o Screen/screen_test.out Screen/Screen.o Screen/screen_test.cpp
	cd explicit; make
	rm $(OBJ)
person/person.o: person/person.cpp 
	g++ -o person/person.o -c person/person.cpp
X_and_Y/X_and_Y_test.o: X_and_Y/X_and_Y_test.cpp
	g++ -o X_and_Y/X_and_Y_test.o -c X_and_Y/X_and_Y_test.cpp
mutable_test.o: mutable_test.cpp
	g++ -o mutable_test.o -c mutable_test.cpp
Screen/Screen.o: Screen/Screen.cpp
	g++ -o Screen/Screen.o -c Screen/Screen.cpp
.PHONY: clean
clean:
	rm $(TARGET)

