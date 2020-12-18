INCLUDE=Include/
SOURCES=$(wildcard src/*.c)
build:
	g++ -I$(INCLUDE) -o main.o $(SOURCES)
