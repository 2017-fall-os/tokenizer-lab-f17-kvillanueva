/*Lab1: Tokenizer
  Name: Kristian Villanueva
  Last Modification: 9/10/17
 */
all: test

CFLAGS = -g -O2

test: test.o mytoc.o 
	cc -o test test.o mytoc.o
clean:
	rm -f  *.o test

demo: test
	./test