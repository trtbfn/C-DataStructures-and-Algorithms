#include <stdio.h>
#include <stdlib.h>
#include "circularlinkedlist.h"

int main(void) {
    IntCLL *cll = intCLL_make_list();
    for(int i = 0; i < 7; i++) 
        intCLL_insert(intCLL_create_node(i), cll);
    intCLL_display(cll);
    return 0;
}