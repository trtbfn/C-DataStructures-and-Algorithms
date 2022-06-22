#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

struct IntLLNode {
    int data;
    struct IntLLNode *next;
};

struct IntLL {
    IntLLNode *head;
};

IntLLNode *intLL_create_node(int data) {
    IntLLNode *node = malloc(sizeof(IntLLNode));
    if(!node) {
        return NULL;
    }
    node -> data = data;
    node -> next = NULL;
    return node;
}

IntLL *intLL_make_list(void) {
    IntLL *list = malloc(sizeof(IntLL));
    if(!list) {
        return NULL;
    }
    list -> head = NULL;
    return list;
}

void intLL_insert(IntLLNode *new, IntLL *list) {
    if(list -> head == NULL) {
        list -> head = new;
        return;
    }
    new -> next = list -> head;
    list -> head = new;
}

void intLL_insert_last(IntLLNode *new, IntLL *list) {
    if(list -> head == NULL) {
        list -> head = new;
        return;
    }
    IntLLNode *current = list->head;
    while(current -> next != NULL) 
        current = current -> next;
    current -> next = new;
}
    
void intLL_insert_after(IntLLNode *target, 
    IntLLNode *new, IntLL *list) {

    if(list -> head == NULL) return;

    if(list -> head -> next == NULL 
        && list -> head -> data == target -> data) {
        
        list -> head -> next = new;
        return;
    }
        

    IntLLNode *current = list -> head;

    while(current -> data != target -> data 
            && current -> next != NULL)
                current = current -> next;

    if(current -> next != NULL) {
        IntLLNode *next = current->next;
        current->next = new;
        new->next = next;
    }
    else 
        current -> next = new;
}

void intLL_insert_before(IntLLNode *target, 
    IntLLNode *new, IntLL *list) {

    if(list -> head == NULL) return;

    if(list -> head -> next == NULL 
        && list -> head == target) {
        
        new -> next = list -> head;
        list -> head = new;
        return;
    }

    if(list -> head -> data 
        == target -> data) {

        new -> next = list ->head;
        list -> head = new;
    }
        

    IntLLNode *current = list -> head;
    IntLLNode *prev = NULL;

    while(current -> data != target -> data
            && current -> next != NULL) {
                prev = current;
                current = current -> next;
    }
                
    prev -> next = new;
    new -> next = current;
}

void intLL_display(IntLL *list) {
    if(list -> head == NULL) {
        printf("[ ]\n");
        return;
    };

    if(list -> head -> next == NULL) {
        printf("[ %d ]\n", list->head->data);
        return;
    }
    
    IntLLNode *current = list -> head;

    printf("[ ");
    for(; current->next != NULL;
        current = current->next) 
            printf("%d, ", current->data);
    printf("%d ]\n", current->data);
}

unsigned char intLL_is_empty(IntLL *list) {
    return list -> head == NULL? 1: 0;
}

void intLL_delete(IntLLNode *target, IntLL *list) {
    if(list->head == NULL) return;

    IntLLNode *current = list->head;

    if(current -> data 
        == target -> data) {
        
        list -> head = current -> next;
        free(current);
        return;
    }

    
    IntLLNode *prev = NULL;

    while(current -> next != NULL && current -> data != target -> data) {
        prev = current;
        current = current -> next;
    }

    if(current -> data 
        != target -> data) 
            return;

    if(current -> next != NULL) {
        prev -> next = current -> next;
        free(current);
    } else {
        prev -> next = NULL;
        free(current);
    }
}

void intLL_delete_first(IntLL *list) {
    if(list -> head == NULL) return;
    if(list -> head -> next == NULL) {
        free(list -> head);
        list -> head = NULL;
        return;
    }
    
    IntLLNode *next = list -> head -> next;
    free(list->head);
    list -> head = next;
}

void intLL_delete_last(IntLL *list) {
    if(list -> head == NULL) return;
    if(list -> head -> next == NULL) {
        free(list -> head);
        list -> head = NULL;
        return;
    }
    
    IntLLNode *current = list -> head;
    while(current -> next -> next != NULL) 
        current = current->next;
    free(current -> next);
    current->next = NULL;
}


void intLL_destroy(IntLL *list) {

  if(list -> head == NULL) return;

  if(list -> head -> next == NULL) {
    free(list -> head);
    list -> head = NULL;
    return;
  }

  IntLLNode *current = list -> head;
  IntLLNode *prev = NULL;

  while(current -> next != NULL) {
    prev = current;
    current = current -> next;
    free(prev);
  }
  free(current);
  list->head = NULL;
}