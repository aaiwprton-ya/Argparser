CFLAGS := -Wall -g -std=c++20
test_args := --arg1 value1 -a2=value2

argparser.a: argparser.o
	ar rcs $@ $^

argparser.o: argparser.cpp argparser.h
	g++ $(CFLAGS) -c -o $@ $<

test.out: test.cpp | argparser.a
	g++ $(CFLAGS) -o $@ $^ argparser.a

.PHONY: test debug clean

test: test.out
	./test.out $(test_args)

debug: test.out
	gdb --args ./test.out $(test_args)

clean:
	rm *.o *.a *.out

