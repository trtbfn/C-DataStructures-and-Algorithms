#include <stdio.h>
#include <stdlib.h>
#include "doublylinkedlist.h"

int main(void) {
    IntDLL *dll = intDLL_create_list();
    for(int i = 5; i > 0; i--) 
        intDLL_insert(
            intDLL_create_node(i),
            dll
        );
    intDLL_display(dll);
    intDLL_insert_after(
        intDLL_create_node(5),
        intDLL_create_node(3),
        dll
    );
    intDLL_display(dll);
    intDLL_insert_before(
        intDLL_create_node(10),
        intDLL_create_node(2),
        dll
    );
    intDLL_display(dll);
    intDLL_insert_before(
        intDLL_create_node(10),
        intDLL_create_node(2),
        dll
    );
    intDLL_display(dll);
    return 0;
}