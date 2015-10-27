BIN = cfc.out
OBJS = parser.o cfc.o document.o

CC = g++
DEBUG = -g
CFLAGS = -c -std=c++11
LFLAGS = -Wall

all: pt clean 

pt: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(BIN)
parser.o: parser.cpp
	$(CC) $(CFLAGS) parser.cpp
document.o:
	$(CC) $(CFLAGS) document.cpp
cfc.o: cfc.cpp parser.cpp
	$(CC) $(CFLAGS) cfc.cpp
clean:
	rm *.o