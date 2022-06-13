#include <stdio.h>
#include <stdlib.h>
#include "doublylinkedlist.h"

int main(void) {
    List *list = MakeList();
    for(int i = 0; i < 6; i++) 
        Insert(i, list);
    Display(list);
    InsertAfter(5, 10, list);
    InsertAfter(60, 5, list);
    Display(list);
    return 0;
}