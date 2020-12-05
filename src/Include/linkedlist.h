#include "stdbool.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct NodeT {
    int data;
    struct NodeT* next;
} Node;

typedef struct LinkedListT {
    unsigned int size; 
    Node* nodes;
} LinkedList;

LinkedList* create_list();

void put(LinkedList* list, int data);

int remove_first(LinkedList* list);

void print(LinkedList* list);

bool is_empty(LinkedList* list);