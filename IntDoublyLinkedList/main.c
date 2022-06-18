#include <stdio.h>
#include <stdlib.h>
#include "doublylinkedlist.h"

int main(void) {
    IntDLL *dll = intDLL_create_list();

    for(int i = 0; i < 6; i++) 
        intDLL_insert(
            intDLL_create_node(i),
            dll
    );
    intDLL_display(dll);
    return 0;
}