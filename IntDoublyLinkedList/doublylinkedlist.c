#include <stdio.h>
#include <stdlib.h>
#include "doublylinkedlist.h"

struct IntDLLNode {
  int data;
  IntDLLNode *next; 
  IntDLLNode *prev;
};

//Doubly Linked List
struct IntDLL {
  IntDLLNode *head;  
};

IntDLLNode *intDLL_create_node(int data) {
    IntDLLNode *node = malloc(sizeof(data));
    if(!node)
        return NULL;
    node -> data = data;
    node -> next = NULL;
    node -> prev = NULL;

    return node;
}

IntDLL *intDLL_create_list(void) {
    IntDLL *list = malloc(sizeof(IntDLL));
    if(!list)
        return NULL;
    list -> head = NULL;

    return list;
}

void intDLL_display(IntDLL *list) {
  if(list -> head == NULL) {
    printf("[ ]\n");
    return;
  }

  if(list -> head -> next == NULL) {
    printf("[ %d ]\n", list -> head -> data);
    return;
  }

  IntDLLNode *current = list -> head;
  printf("[");

  for(; current -> next != NULL; 
        current = current -> next) 
    printf("%d, ", current -> data);

  printf("%d]\n", current -> data);
}

void intDLL_insert(IntDLLNode *new, IntDLL *list) {
  if(list -> head == NULL) 
    list -> head = new;
  else {
    new -> next = list -> head;
    list -> head->prev = new;
    list -> head = new;
  }
}

void intDLL_insert_after(IntDLLNode *target,
    IntDLLNode *new, IntDLL *list) {

  if(list -> head == NULL) return;

  if(list -> head -> next == NULL
      && list -> head -> data == target -> data) {

    list -> head -> next = new;
    new -> prev = list -> head;

    return;
  }
  
  IntDLLNode *current = list -> head;
  while(current -> data != target -> data
     && current -> next != NULL) 
      current = current -> next;

  if(current -> data == target -> data) {
    if(current -> next != NULL) {
    IntDLLNode *next = current -> next;

    current -> next = new;
    new->prev = current;
        
    new->next = next;
    next->prev = new;
    } else 
      current -> next = new;
  }
}

void intDLL_insert_before(IntDLLNode *target,
    IntDLLNode *new, IntDLL *list) {

  if(list -> head == NULL) return;

  if(list -> head -> next == NULL
      && list -> head -> data == target -> data) {

    new -> next = list -> head;
    list -> head -> prev = new;
    list -> head = new;

    return;
  }

  if(list -> head -> data == target -> data) {

    new -> next = list -> head;
    list -> head -> prev = new;
    list -> head = new;

    return;
  }
  
  IntDLLNode *current = list -> head;
  while(current -> data != target -> data
     && current -> next != NULL) 
      current = current -> next;

  if(current -> data == target -> data) {
    IntDLLNode *prev = current -> prev;
  
    prev -> next = new;
    new -> prev = prev;
        
    new -> next = current;
    current->prev = new;
  }
}

void intDLL_insert_first(IntDLLNode *new, IntDLL *list) {

  if(list -> head == NULL) {
    list -> head = new;
    return;
  } 

  new -> next = list -> head;
  list -> head -> prev = new;
  list -> head = new;
}

void intDLL_insert_last(IntDLLNode *new, IntDLL *list) {

  if(list -> head == NULL) {
    list -> head = new;
    return;
  } 

  IntDLLNode *current = list -> head;
    while(current -> next != NULL)
      current = current -> next;
    current -> next = new;
    new -> prev = current;
}

void intDLL_delete(IntDLLNode *target, IntDLL *list) {

  if(list -> head == NULL) return;

  if(list -> head -> next == NULL
    && list -> head -> data 
      == target -> data) {

    free(list -> head);
    list -> head = NULL;
    return;
  }

  if(list -> head -> data 
      == target -> data) {

    IntDLLNode *next = list -> head -> next;
    next -> prev = NULL;
    free(list -> head);
    list -> head = next;
    return;
  }
  
  IntDLLNode *current = list -> head;
  while(current -> next != NULL 
        && current -> data != target -> data)
          current = current -> next;

  if(current -> data != target -> data) 
    return;

  if(current -> next != NULL) {
    current -> next -> prev = current -> prev;
    current -> prev -> next = current -> next;
  } else 
    current -> prev -> next = NULL;
  free(current);
}

void intDLL_delete_first(IntDLL *list) {
  if(list -> head == NULL) return;

  if(list -> head ->next == NULL) {
    free(list -> head);
    list -> head = NULL;
    return;
  }

  IntDLLNode *next = list -> head -> next;
  next -> prev = NULL;
  free(list -> head);
  list -> head = next;
}

void intDLL_delete_last(IntDLL *list) {
  if(list -> head == NULL) return;

  if(list -> head -> next == NULL) {
    free(list -> head);
    list -> head = NULL;
    return;
  }

  IntDLLNode *current = list -> head;
  while(current -> next != NULL)
    current = current -> next;
  current -> prev -> next = NULL;
  free(current);
}

void intDLL_destroy(IntDLL *list) {

  if(list -> head == NULL) return;

  if(list -> head ->next == NULL) {
    free(list -> head);
    list -> head = NULL;
    return;
  }

  IntDLLNode *current = list->head;
  while(current -> next != NULL) {
    current = current -> next;
    free(current->prev);
  }
  free(current);
  list->head = NULL;
}



