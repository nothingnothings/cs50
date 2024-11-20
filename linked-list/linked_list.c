#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int number;
    struct node *next;
} node 

int main (void) {
    
    node *list = NULL; // * always initialize pointers to NULL, to avoid segmentation faults (due to garbage values in the pointer slot)

    node *n = malloc(sizeof(node));

    if (n == NULL) {
        free(list);
        return 1;
    }

    n->number = 1;
    n->next = NULL;

    list = n;

    n = malloc(sizeof(node));

    if (n == NULL) {
        free(list);
        return 1;
    }

    n->number = 2;
    n->next = NULL;

    list->next = n;

    n = malloc(sizeof(node));

    if (n == NULL) {
        free(list);
        return 1;
    }

    n->number = 3;
    n->next = NULL;

    list->next->next = n;

    for (node *tmp = list; tmp != NULL; tmp = tmp->next) {
        printf("%i\n", tmp->number);
    }

    // Free the list and all nodes
    while (list != NULL) 
    {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }


}