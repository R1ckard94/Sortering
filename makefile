program: main.o
	g++ main.o sortFunctions.o dataGenerate.o time.o dataReport.o -o main

main.o: main.cpp
	g++ -std=c++17 -c main.cpp sortFunctions.cpp time.cpp dataReport.cpp dataGenerate.cpp

clean:
	rm *.o main
