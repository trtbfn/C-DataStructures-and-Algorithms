#include <stdio.h>
#include <stdlib.h>
#include "circularlinkedlist.h"

struct IntCLLNode {
    int data;
    IntCLLNode *next;
};

struct IntCLL {
    IntCLLNode *head;
};

IntCLLNode *intCLL_create_node(int data) {
    IntCLLNode *node = malloc(sizeof(IntCLLNode));
    if(!node) {
        return NULL;
    }
    node -> data = data;
    node -> next = NULL;
    return node;
}

IntCLL *intCLL_make_list(void) {
    IntCLL *list = malloc(sizeof(IntCLL));
    if(!list) {
        return NULL;
    }
    list -> head = NULL;
    return list;
}

void intCLL_insert(IntCLLNode *new, IntCLL *list) {
    if(list -> head == NULL) {
        list -> head = new;
        new -> next = list -> head;
        return;
    }
    
    IntCLLNode *current = list -> head;
    while(current -> next != list -> head) 
        current = current -> next;
    
    current -> next = new;
    new -> next = list -> head;
    list -> head = new;
}

void intCLL_display(IntCLL *list) {
    if(list -> head == NULL) {
        printf("[ ]\n");
        return;
    };

    if(list -> head -> next == list -> head) {
        printf("[ %d ]\n", list->head->data);
        return;
    }
    
    IntCLLNode *current = list -> head;

    printf("[ ");
    for(; current->next != list -> head;
        current = current->next) 
            printf("%d, ", current->data);
    printf("%d ]\n", current->data);
}
