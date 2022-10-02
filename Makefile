#target: dependencies
#	command

# create executable of the application  
textManipulation: main.o textOccurence.o textReverse.o
		g++ main.o textOccurence.o textReverse.o -o textManipulation -std=c++17

# compile main.cpp
main.o: main.cpp
		g++ -c main.cpp -std=c++17
# compile textOccurence (.cpp and .h)
textOccurence.o: textOccurence.cpp textOccurence.h 
		g++ -c textOccurence.cpp -std=c++17

# compile textReverse (.cpp and .h)
textReverse.o:textReverse.cpp textReverse.h
		g++ -c textReverse.cpp -std=c++17

# clean all .o files and app executable 
clean:
	rm *.o textManipulation
