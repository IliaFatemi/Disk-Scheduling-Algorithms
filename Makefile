CC = gcc
CFLAGS := -Werror -Wfatal-errors -g
LDFLAGS =

SRC = DSSimul.c
OBJ = $(SRC:.c=.o)
EXECUTABLE = DSSimul

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) -pthread $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(filter-out list.o, $(OBJ)) $(EXECUTABLE)
	rm -f assignment3.zip

zip:
	rm -f assignment3.zip
	zip assignment4.zip Makefile DSSimul.c