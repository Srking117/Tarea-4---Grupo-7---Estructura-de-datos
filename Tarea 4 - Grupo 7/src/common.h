#ifndef COMMON_H
#define COMMON_H

#define MAX_NAME_LEN 32

typedef struct Edge {
    int to;
    int weight;
    struct Edge* next;
} Edge;

typedef struct Node {
    char name;          
    Edge* edges;        
} Node;

typedef struct Graph {
    int size;           
    Node* nodes;        
} Graph;

#endif 
