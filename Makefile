CFLAGS := -Wall -g -std=c++20
test_args := --arg1 -123 --arg2 123 --arg3 0.123 --arg4 c --arg5 wqerty --arg6 {12, 23, 34} --arg7 {str1, str2,str3 , str4, str5} --arg8 {10:ten, 20:twenty, 30:thirty, 40:fourty, 50:fifty}

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

