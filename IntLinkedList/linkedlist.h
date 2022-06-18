#ifndef LINKEDLIST_HEADER
#define LINKEDLIST_HEADER

typedef struct IntLLNode IntLLNode; 
typedef struct IntLL IntLL;

IntLL *intLL_make_list(void);
IntLLNode *intLL_create_node(int);

//Insert an element at head of list
void intLL_insert(IntLLNode *, IntLL *);
void intLL_insert_last(IntLLNode *, IntLL *);

void intLL_insert_after(IntLLNode *target, 
    IntLLNode *new, IntLL *list);

void intLL_insert_before(IntLLNode *target, 
    IntLLNode *new, IntLL *list);

void intLL_display(IntLL *);
unsigned char intLL_is_empty(IntLL *);

void intLL_delete(IntLLNode *, IntLL *);
void intLL_delete_first(IntLL *);
void intLL_delete_last(IntLL *);
void intLL_destroy(IntLL *);

#endif