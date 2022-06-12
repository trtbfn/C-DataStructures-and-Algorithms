#ifndef DOUBLYLINKEDLIST_HEADER
#define DOUBLYLINKEDLIST_HEADER

typedef struct node Node; 
typedef struct list List;

List *MakeList();
void Display(List *list);
void DisplayBackward(List *list);
void Insert(int data, List *list);
void InsertAtHead(int data, List *list);
void InsertAfter(int item, int data, List *list);
void Delete(int item, List *list);
void DeleteLast(List *list);
void Destroy(List *list);

#endif