CC = gcc
CFLAGS := -Werror -Wfatal-errors -g
LDFLAGS =

SRC = DSSimul.c dsa.c
OBJ = $(SRC:.c=.o)
EXECUTABLE = DSSimul

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) -pthread $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(filter-out list.o, $(OBJ)) $(EXECUTABLE)
	rm -f assignment4.zip

zip:
	rm -f assignment4.zip
	zip assignment4.zip Makefile DSSimul.c dsa.h dsa.c