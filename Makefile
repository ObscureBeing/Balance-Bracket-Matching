CC = gcc
CFLAGS = -Wall -pedantic -ansi -Werror -g
OBJ = BracketPair.o Errors.o ErrorsProcessing.o LinkedList.o MatchPairs.o Substrings.o newSleep.o visualize.o FileIO.o UpdateStrings.o
EXEC = ErrorsProcessing
  
$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)
  
Bracketpair.o : BracketPair.c BracketPair.h
	$(CC) -c BracketPair.c $(CFLAGS) 
Errors.o : Errors.c Errors.h LinkedList.h UpdateStrings.h visualize.h MatchPairs.h BracketPair.h
	$(CC) -c Errors.c $(CFLAGS)
ErrorsProcessing.o : ErrorsProcessing.c FileIO.h Errors.h 
	$(CC) -c ErrorsProcessing.c $(CFLAGS)
LinkedList.o : LinkedList.c LinkedList.h 
	$(CC) -c LinkedList.c $(CFLAGS)
MatchPairs.o : MatchPairs.c MatchPairs.h
	$(CC) -c MatchPairs.c $(CFLAGS)
Substrings.o : Substrings.c Substrings.h
	$(CC) -c Substrings.c $(CFLAGS)
newSleep.o : newSleep.c newSleep.h
	$(CC) -c newSleep.c $(CFLAGS)
visualize.o : visualize.c visualize.h newSleep.h LinkedList.h 
	$(CC) -c visualize.c $(CFLAGS)
FileIO.o : FileIO.c FileIO.h
	$(CC) -c FileIO.c $(CFLAGS)
UpdateStrings.o : UpdateStrings.c UpdateStrings.h Substrings.h LinkedList.h 
	$(CC) -c UpdateStrings.c $(CFLAGS)


ifdef STACK
CFLAGS += -D STACK
STACK : clean $(EXEC)
endif

clean :
	rm -f $(EXEC) $(OBJ)
