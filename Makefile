CC = g++
CFLAGS = -Wall 

RM = rm -f

all: crater

crater: crater.cpp 
	$(CC) $(CFLAGS) -o crater crater.cpp

clean:
	$(RM) crater


	 
