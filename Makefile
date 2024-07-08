output: main.o message.o
	g++ main.o message.o -o output

main.o: main.cpp
	g++ -c main.cpp

# Comments from https://www.gnu.org/software/make/manual/html_node/Makefile-Contents.html
# the -c is a parameter to ensure that an executable is not created

target: dependencies
	action