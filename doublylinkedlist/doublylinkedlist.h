#ifndef DOUBLYLINKEDLIST_HEADER
#define DOUBLYLINKEDLIST_HEADER


// * System type defenitions
typedef struct IntDLLNode IntDLLNode; 
typedef struct IntDLL IntDLL;
// Don't pay attention on it*

IntDLLNode *intDLL_create_node(int);
IntDLL *intDLL_create_list(void);

void intDLL_display(IntDLL *);

// // Insertion at the beginning 
// // of the list by default.
void intDLL_insert(IntDLLNode *, IntDLL *);
void intDLL_insert_first(IntDLLNode *, IntDLL *); 
void intDLL_insert_last(IntDLLNode *, IntDLL *); 
void intDLL_insert_after(IntDLLNode *new, IntDLLNode *target, IntDLL *list);
void intDLL_insert_before(IntDLLNode *new, IntDLLNode *target, IntDLL *list); 

// // Delete element at the 
// // beginnig of the list 
// // by default.
// void intDLL_delete(int item, List *list);
// void intDLL_deleteLast(List *list);


// // * Implement functions for makeing live
// // a little bit easier *.
// void intDLL_destroy(List *list);

#endif