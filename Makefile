CFLAGS=-std=c23 -g -Wall -I include
CC=gcc
UNITY=./unity
APP_EXE=build/main
TEST_EXE=build/test

.PHONY: all init test doc clean

all: $(APP_EXE)

init:
	mkdir -p build

build/unity.o: $(UNITY)/unity.c $(UNITY)/unity.h | init
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

build/stack.o: include/stack.h src/stack.c | init
	$(CC) $(CFLAGS) -c src/stack.c -o build/stack.o

build/main.o: src/main.c include/stack.h | init
	$(CC) $(CFLAGS) -c src/main.c -o build/main.o

build/test.o: test/test.c include/stack.h | init
	$(CC) $(CFLAGS) -I $(UNITY) -c test/test.c -o build/test.o

$(APP_EXE): build/stack.o build/main.o
	$(CC) $(CFLAGS) build/stack.o build/main.o -o $(APP_EXE)

test: init build/unity.o build/stack.o build/test.o
	$(CC) $(CFLAGS) build/unity.o build/stack.o build/test.o -o $(TEST_EXE)

doc:
	doxygen Doxyfile

clean:
	rm -rf build/ doc/
