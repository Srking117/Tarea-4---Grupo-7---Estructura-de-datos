CC=gcc
CFLAGS=-Wall -O2

SRC = src/main.c \
      src/graph.c src/memory_manager.c src/file_reader.c \
      src/interface.c src/command_parser.c src/graph_utils.c \
      src/hamiltonian.c src/path_finder.c src/tsp_solver.c

OBJ = $(SRC:.c=.o)

all: pvv

pvv: $(OBJ)
	$(CC) $(CFLAGS) -o pvv $(OBJ)

clean:
	rm -f src/*.o pvv

