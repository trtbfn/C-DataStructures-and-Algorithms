#ifndef CIRCULARLINKEDLIST_HEADER
#define CIRCULARLINKEDLIST_HEADER

typedef struct IntCLLNode IntCLLNode; 
typedef struct IntCLL IntCLL;

IntCLL *intCLL_make_list(void);
IntCLLNode *intCLL_create_node(int);

//Insert an element at head of list
void intCLL_insert(IntCLLNode *, IntCLL *);
// void intСLL_insert_last(IntСLLNode *, IntCLL *);

// void intСLL_insert_after(IntСLLNode *target, IntСLLNode *new, IntСLL *list);

// void intСLL_insert_before(IntCLLNode *target, IntСLLNode *new, IntСLL *list);

void intCLL_display(IntCLL *);
// unsigned char intLL_is_empty(IntСLL *);

// void intLL_delete(IntСLLNode *, IntСLL *);
// void intLL_delete_first(IntСLL *);
// void intLL_delete_last(IntСLL *);
// void intLL_destroy(IntСLL *);

#endif