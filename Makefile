CC=gcc
SRC=src/hora.c
CFLAGS=-Wall -std=c17

BIN=hora

OBJ=$(SRC:.c=.o)

all:  $(BIN)

$(BIN): $(OBJ)
	$(CC) $(LIBS) $(OBJ) -o $(@)
	@rm -f $(OBJ)
	@rm -f *~

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@rm -f *~
	@rm -f $(BIN)