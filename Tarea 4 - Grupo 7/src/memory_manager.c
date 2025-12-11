#include <stdio.h>
#include <stdlib.h>
#include "memory_manager.h"


void* mm_alloc(unsigned int size) {
    void* ptr = malloc(size);
    if (!ptr) {
        fprintf(stderr, "Error: no se pudo asignar memoria.\n");
        exit(1);
    }
    return ptr;
}
