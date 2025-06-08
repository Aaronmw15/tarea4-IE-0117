CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Archivos fuente
SRCS = main.c stack.c linked_list.c
# Archivos objeto (automáticamente generados desde los .c)
OBJS = $(SRCS:.c=.o)

# Nombre del ejecutable
TARGET = programa

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)