#include <stdio.h>
#include <stdlib.h>
#include "doublylinkedlist.h"

struct node {
  int data;
  Node *next; 
  Node *prev;
};

struct list {
  Node *head;  
};

Node *CreateNode();

Node *CreateNode() {
    Node *newNode = malloc(sizeof(Node));
    if(!newNode) 
        return NULL;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

List *MakeList() {
    List *list = malloc(sizeof(List));
    if(!list)
        return NULL;
    list->head = NULL;

    return list;
}

void Display(List *list) {
  Node *current = list->head;
  printf('[');
  for(; current->next != NULL; current=current->next) 
    printf("%d ", current->data);
  printf(']');
}

void DisplayBackward(List *list) {
  Node *current = list->head;
  for(; current->next != NULL; current=current->next) {};
  printf('[');
    for(; current->prev != NULL; current=current->prev);
      printf("%d ", current->data);
  printf(']');
}

//Insert data at the end
void Insert(int data, List *list) {
  Node *newNode = CreateNode();
  newNode->data = data;

  if(list->head == NULL) {
    list->head = newNode;
  } else {
    Node *current = list->head;
    while(current->next != NULL) 
      current = current->next;
    current->next = newNode;
    newNode->prev = current;
  }
}

void InsertAfter(int item, int data, List *list) {
  if(list->head == NULL) return;
  
  Node *newNode = CreateNode();
  newNode = data;

  Node *current = list->head;
  while(current->data != item && current != NULL) 
    current = current->next;

  if(current->next == NULL) 
    current->next = newNode;
  else {
    Node *prev = current; 
    current = current->next;

    prev->next = newNode;
    newNode->prev = prev;
    
    newNode->next = current;
    current->prev = newNode;
  }
}

void InsertAtHead(int data, List *list) {
  Node *newNode = CreateNode();
  newNode->data = data;

  if(list->head == NULL) {
    list->head = newNode;
  } else {
    newNode->next = list->head->prev;
    list->head = newNode;
  }
}

void _CheckOccupancy(List *list);

// Block for delete functions 
void _CheckOccupancy(List *list) {
  if(list->head == NULL) return;
  if(list->head->next == NULL) {
    free(list->head);
    list->head = NULL;
  }
}

void Delete(int item, List *list) {
  _CheckOccupancy(list);

  Node *current = list->head;
  while(current->data != item && current->next != NULL)
    current = current->next;

  if(current->next == NULL) {
    current->prev->next = NULL;
    free(current);
  } else {
    current->next->prev = current->prev;
    current->prev->next = current->next;
    free(current);
  }
}

void DeleteLast(List *list) {
  _CheckOccupancy(list);

  Node *current = list->head;
  while(current != NULL) 
    current->next = current;

  current->prev->next = NULL;
  free(current);
}

void Destroy(List *list) {
  _CheckOccupancy(list);

  Node *current = list->head;
  while(current != NULL) {
    current->next = current;
    free(current->prev);
  }
  free(current);
  list->head = NULL;
}



