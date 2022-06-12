#include <stdio.h>
#include <stdlib.h>
#include "linked-list.h"

struct node {
    int data;
    struct node *next;
};

struct list {
    Node *head;
};

Node *createnode(int data);

Node *createnode(int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    if(!newNode) {
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

List *makelist(void) {
    List *list = (List *) malloc(sizeof(List));
    if(!list) {
        return NULL;
    }
    list->head = NULL;
    return list;
}

void display(List *list) {
    if(list->head == NULL)
        return;

    Node *current = list->head;
    for(; current != NULL; current = current->next) 
        printf("%d\n", current->data);
}

void add(int data, List *list) {
    if(list->head == NULL) 
        list->head = createnode(data);
    else {
        Node *current = list->head;
        while(current->next != NULL) 
            current = current->next;
        current->next = createnode(data);
    }
}

void delete(int data, List *list) {
    Node *current = list->head;
    Node *previous = NULL;
    while(current->next != NULL) {
        if(current->data == data) {
            previous->next = current->next;
            if(current == list->head)
                list->head = current->next;
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

void destroy(List *list) {
    Node *current = list->head;
    Node *next = NULL;
    while(current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(list->head);
}

