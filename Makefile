# Makefile para estructura plana (todo en la raíz)
TARGET = pvv_app
CC = gcc
CFLAGS = -Wall -Wextra -g

# Compila todos los archivos .c que encuentre en la carpeta
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET) $(TARGET).exe