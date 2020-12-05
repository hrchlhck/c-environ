#include "linkedlist.h"

LinkedList* create_list() {
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    list->nodes = NULL;
    list->size = 0;
    return list;
}

void put(LinkedList* list, int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    
    if(is_empty(list)) {
        list->nodes = node;
    } else {
        Node* aux = (Node*) malloc(sizeof(Node));
        aux->data = data;
        aux->next = list->nodes;
        list->nodes = aux;
    }

    list->size++;
}

int remove_first(LinkedList* list) {
    Node* aux = (Node*) malloc(sizeof(Node));
    aux = list->nodes;
    
    if(is_empty(list)) {
        perror("ERROR: List is empty.");
        exit(0);
    } else {
        list->nodes = aux->next;
    }
    
    list->size--;
    int data = aux->data;
    free(aux);
    aux = NULL;
    return data;
}

void print(LinkedList* list) {
    Node* aux = (Node*) malloc(sizeof(Node));
    aux = list->nodes;
    int idx = 0;
 
    printf("-----------\n");
    while(aux != NULL) {
        printf("Data at index %d: %d\n", idx, aux->data);
        idx++;
        aux = aux->next;
    }
    printf("------------\n");
    free(aux);
    aux = NULL;
}

bool is_empty(LinkedList* list) {
    if(list->nodes == NULL)
        return true;
    return false;
}