#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(void) {
    List *list = makelist();
    add(1, list);
    add(4, list);
    add(5, list);
    display(list); 
    delete(4, list);
    display(list);
    destroy(list);
    return 0;
    free(list);
}