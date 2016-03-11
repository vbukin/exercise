CC=gcc
TARGET = HW
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)


.PHONY: all clean 

run: $(TARGET)
	./$(TARGET)

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) 
 
%.o: %.c
	$(CC) $(CFLAGS)  -c $< -o $@

clean:
	rm -rf $(TARGET) $(OBJS)
