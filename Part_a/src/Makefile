all: output run

run: output
	./output

output: main.o maze.o graph.o edge.o node.o
	g++ main.o maze.o graph.o edge.o node.o -o output

main.o: main.cpp ../include/maze.h
	g++ -c main.cpp

maze.o: maze.cpp ../include/graph.h
	g++ -c maze.cpp

graph.o: graph.cpp ../include/edge.h
	g++ -c graph.cpp

edge.o: edge.cpp ../include/node.h
	g++ -c edge.cpp

node.o: node.cpp
	g++ -c node.cpp