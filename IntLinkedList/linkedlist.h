#ifndef LINKEDLIST_HEADER
#define LINKEDLIST_HEADER

typedef struct IntLLNode IntLLNode; 
typedef struct IntLinkedList IntLinkedList;

IntLinkedList *intLL_make_list(void);
IntLLNode *intLL_create_node(int);

//Insert an element at head of list
void intLL_insert(IntLLNode *, IntLinkedList *);
void intLL_insert_last(IntLLNode *, IntLinkedList *);

void intLL_insert_after(IntLLNode *target, 
    IntLLNode *new, IntLinkedList *list);

void intLL_insert_before(IntLLNode *target, 
    IntLLNode *new, IntLinkedList *list);

void intLL_display(IntLinkedList *);
unsigned char intLL_is_empty(IntLinkedList *);

void intLL_delete(IntLLNode *, IntLinkedList *);
void intLL_delete_first(IntLinkedList *);
void intLL_delete_last(IntLinkedList *);

#endif