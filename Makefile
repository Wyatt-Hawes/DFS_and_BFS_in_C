CC = gcc
CFLAGS = -std=c17 -Wall -Werror -Wextra -Wpedantic -g#$(shell pkg-config --cflags)

all: GraphTest FindComponents

GraphTest: GraphTest.o Graph.o List.o
	$(CC) -o $@ $^

FindComponents: Graph.o List.o FindComponents.o
	$(CC) -o $@ $^


%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean: spotless
	rm -f *.o
	
spotless: clean
	rm -f GraphTest FindComponents
