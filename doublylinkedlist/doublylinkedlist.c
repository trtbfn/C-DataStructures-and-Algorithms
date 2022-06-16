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
    printf("[ ]");
    return;
  }

  if(list -> head -> next == NULL) {
    printf("[ %d ]", list -> head -> data);
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

// void InsertLast(int data, List *list) {
//   Node *newNode = CreateNode();
//   newNode->data = data;

//   if(list->head == NULL) {
//     list->head = newNode;
//   } else {
//     Node *current = list->head;
//     while(current->next != NULL)
//       current = current->next;
//     current->next = newNode;
//   }
// }

// void _CheckOccupancy(List *list);

// // Block for delete functions 
// void _CheckOccupancy(List *list) {
//   if(list->head == NULL) return;
//   if(list->head->next == NULL) {
//     free(list->head);
//     list->head = NULL;
//   }
// }

// void Delete(int item, List *list) {
//   _CheckOccupancy(list);

//   Node *current = list->head;
//   while(current->data != item && current->next != NULL)
//     current = current->next;

//   printf("%d", current->data);

//   if(current->next == NULL) {
//     current->prev->next = NULL;
//     free(current);
//   } else if(list->head == current) {
//     current = current->next;
//     current->prev = NULL;
//     free(list->head);
//     list->head = current;
//   } else {
//     current->next->prev = current->prev;
//     current->prev->next = current->next;
//     free(current);
//   }
// }

// void DeleteLast(List *list) {
//   _CheckOccupancy(list);

//   Node *current = list->head;
//   while(current != NULL) 
//     current->next = current;

//   current->prev->next = NULL;
//   free(current);
// }

// void Destroy(List *list) {
//   _CheckOccupancy(list);

//   Node *current = list->head;
//   while(current != NULL) {
//     current->next = current;
//     free(current->prev);
//   }
//   free(current);
//   list->head = NULL;
// }



