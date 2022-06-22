#include <stdio.h>
#include <stdlib.h>
#include "circularylinkedlist.h"

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

void intCLL_insert_first(IntCLLNode *new, IntCLL *list) {
    if(list -> head == NULL) {
        list -> head = new;
        new -> next = list -> head;
        return;
    }

    IntCLLNode *prev = list -> head;
    while(prev -> next != list -> head) 
        prev = prev -> next;

    prev -> next = new;
    new -> next = list -> head;
    list -> head = new;
}

void intCLL_insert_last(IntCLLNode *new, IntCLL *list) {
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
}

void intCLL_insert_after(IntCLLNode *target, 
    IntCLLNode *new, IntCLL *list) {

    if(list -> head == NULL) return;

    if(list -> head -> next == list -> head
        && list -> head -> data == target -> data) {
        
        list -> head -> next = new;
        new -> next = list -> head;

        return;
    }
        

    IntCLLNode *current = list -> head;

    while(current -> data != target -> data 
            && current -> next != list -> head)
                current = current -> next;

    if(current -> data != target -> data) 
        return;

    if(current -> next != list -> head) {
        IntCLLNode *next = current -> next;
        current -> next = new;
        new -> next = next;
    }
    else {
        current -> next = new;
        new -> next = list -> head;
    }   
        
}

void intCLL_insert_before(IntCLLNode *target, 
    IntCLLNode *new, IntCLL *list) {

    if(list -> head == NULL) return;

    if(list -> head -> next == list -> head 
        && list -> head -> data == target -> data) {
        
        list -> head -> next = new;
        new -> next = list -> head;
        list -> head = new;

        return;
    }

    IntCLLNode *prev = list -> head;

    if(list -> head -> data 
        == target -> data) {
        
        while(prev -> next != list -> head)
            prev = prev -> next;
        prev -> next = new;
        new -> next = list -> head;
        list -> head = new;

        return;
    }
        
    IntCLLNode *current = list -> head;
    
    while(current -> data != target -> data
            && current -> next != list -> head) {
        
        prev = current;
        current = current -> next;
    }

    if(current -> data != target -> data) 
        return;
                
    prev -> next = new;
    new -> next = current;
}

void intCLL_delete(IntCLLNode *target, IntCLL *list) {
    if(list -> head == NULL) return;

    if(list -> head -> data == target -> data
        && list -> head -> next == list -> head) {
        
        free(list -> head);
        list -> head = NULL;
        return;
    }

    IntCLLNode *current = list -> head;
    IntCLLNode *prev = list -> head;

    if(current -> data == target -> data) {
        while(prev -> next != list -> head)
            prev = prev -> next;
        prev -> next = current -> next;
        list -> head = current -> next;
        free(current);

        return;
    }

    while(current -> next != list -> head 
        && current -> data != target -> data) {

        prev = current;
        current = current -> next;      
    }

    if(current -> data 
        != target -> data) 
            return;

    if(current -> next != list -> head) {
        prev -> next = current -> next;
        free(current);
    } else {
        prev -> next = list -> head;
        free(current);
    }
}

void intCLL_delete_first(IntCLL *list) {
    if(list -> head == NULL) return;
    if(list -> head -> next == list -> head) {
        free(list -> head);
        list -> head = NULL;
        return;
    }

    IntCLLNode *prev = list -> head;
    while(prev -> next != list -> head) 
        prev = prev -> next;
    prev -> next = list -> head -> next;

    free(list -> head);
    list -> head = prev -> next;
}

void intCLL_delete_last(IntCLL *list) {
    if(list -> head == NULL) return;
    if(list -> head -> next == list -> head) {
        free(list -> head);
        list -> head = NULL;
        return;
    }
    
    IntCLLNode *current = list -> head;
    while(current -> next -> next != list -> head) 
        current = current -> next;
    free(current -> next);
    current -> next = list -> head;
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
        current = current -> next) 
            printf("%d, ", current -> data);
    printf("%d ]\n", current -> data);
}

void intCLL_destroy(IntCLL *list) {

  if(list -> head == NULL) return;

  if(list -> head -> next == list -> head) {
    free(list -> head);
    list -> head = NULL;
    return;
  }

  IntCLLNode *current = list -> head;
  IntCLLNode *prev = list -> head;

  while(current -> next != list -> head) {
    prev = current;
    current = current -> next;
    free(prev);
  }
  free(current);
  list->head = NULL;
}

unsigned char intCLL_is_empty(IntCLL *list) {
    if(list -> head == NULL) 
        return 1;
}
