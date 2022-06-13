#ifndef DOUBLYLINKEDLIST_HEADER
#define DOUBLYLINKEDLIST_HEADER


// * System type defenitions
typedef struct node Node; 
typedef struct list List;
// Don't pay attention on it*


// Go down.

// Implementation with *one pointer - head pointer*.

// * Basic operations *.

//--flag "t" after function means tested--

// Display elements from last
// inserted element
void Display(List *list);
void DisplayBackward(List *list);

// Insertion at the beginning 
// of the list by default.
void Insert(int data, List *list); //t
void InsertAfter(int item, int data, List *list); //t
void InsertLast(int data, List *list); 

// Delete element at the 
// beginnig of the list 
// by default.
void Delete(int item, List *list);
void DeleteLast(List *list);


// * Implement functions for makeing live
// a little bit easier *.
void Destroy(List *list);
List *MakeList();

#endif