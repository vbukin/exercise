# Project files

TARGET = app
BIN = $(TARGET)
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
DEP = $(SRC:.c=.d)

# Tools and flags

CC = gcc
RM = rm -f
CFLAGS = -Wall -MD
LFLAGS = -Wl,-Map,app.map 

-include $(DEP)

# Targets

.PHONY: all clean run

all: $(BIN)

$(BIN): $(OBJ)
	@echo "Linking $@..."
	@$(CC) $(LFLAGS) -o $@ $^

%.o: %.c
	@ echo "Compiling $<..."
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	@echo "Cleaning..."
	$(RM) $(OBJ) $(DEP) $(BIN)

run: $(BIN)
	@echo "Starting $<..."
	@./$<
	




