#ifndef CIRCULARYLINKEDLIST_HEADER
#define CIRCULARYLINKEDLIST_HEADER
/*
    CircularyLinkedList
        - Head pointer
*/
typedef struct IntCLLNode IntCLLNode; 
typedef struct IntCLL IntCLL;

IntCLL *intCLL_make_list(void);
IntCLLNode *intCLL_create_node(int);

//Insert an element at head of list
void intCLL_insert(IntCLLNode *, IntCLL *);
void intCLL_insert_first(IntCLLNode *, IntCLL *);
void intCLL_insert_last(IntCLLNode *, IntCLL *);
void intCLL_insert_after(IntCLLNode *target, IntCLLNode *new, IntCLL *list);
void intCLL_insert_before(IntCLLNode *target, IntCLLNode *new, IntCLL *list);

void intCLL_display(IntCLL *);
unsigned char intCLL_is_empty(IntCLL *);

void intCLL_delete(IntCLLNode *, IntCLL *);
void intCLL_delete_first(IntCLL *);
void intCLL_delete_last(IntCLL *);
void intCLL_destroy(IntCLL *);

#endif