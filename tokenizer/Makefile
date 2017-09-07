all: TokenMain

CFLAGS = -g -O2

TokenMain: TokenMain.o mytoc.o 
	cc -o TokenMain TokenMain.o mytoc.o
clean:
	rm -f  *.o TokenMain

demo: TokenMain
	./TokenMain
