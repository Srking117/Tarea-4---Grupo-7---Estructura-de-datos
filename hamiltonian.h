#ifndef HAMILTONIAN_H
#define HAMILTONIAN_H

#include "common.h"
#include "graph.h"

/* hamiltoniano_tiene_ciclo:
 - Verifica si el grafo tiene un ciclo hamiltoniano.
 - Un ciclo hamiltoniano recorre todas las ciudades exactamente una vez y regresa a la ciudad de origen.

 * Devuelve:
- true  si existe al menos un ciclo hamiltoniano.
- false en caso contrario o si el grafo es inválido.
 */
bool hamiltoniano_tiene_ciclo(const Grafo *grafo);

#endif // HAMILTONIAN_H
