#ifndef DOUBLYLINKEDLIST_HEADER
#define DOUBLYLINKEDLIST_HEADER

typedef struct IntDLLNode IntDLLNode; 
typedef struct IntDLL IntDLL;

IntDLLNode *intDLL_create_node(int);
IntDLL *intDLL_create_list(void);

void intDLL_display(IntDLL *);

void intDLL_insert(IntDLLNode *, IntDLL *);
void intDLL_insert_first(IntDLLNode *, IntDLL *); 
void intDLL_insert_last(IntDLLNode *, IntDLL *); 
void intDLL_insert_after(IntDLLNode *new, IntDLLNode *target, IntDLL *list);
void intDLL_insert_before(IntDLLNode *new, IntDLLNode *target, IntDLL *list); 

void intDLL_delete(IntDLLNode *, IntDLL *);
void intDLL_delete_first(IntDLL *list);
void intDLL_delete_last(IntDLL *list);
void intDLL_destroy(IntDLL *list);

#endif