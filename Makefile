all: TokenMain

CFLAGS = -g -O2

printFile: TokenMain.o mytoc.o
	cc -o TokenMain TokenMain.o mytoc.o
clean:
	rm -f  *.o TokenMain TokenMain.exe