
output: Driver.o DataClass.o 
	g++ Driver.o DataClass.o  -o output

Driver.o: Driver.cpp
	g++ -c Driver.cpp

DataClass.o: DataClass.cpp
	g++ -c DataClass.cpp

clean: 
	rm *.o output