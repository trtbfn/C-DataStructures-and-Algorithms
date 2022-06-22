#include <stdio.h>
#include <stdlib.h>
#include "circularylinkedlist.h"

int main(void) {
    IntCLL *cll = intCLL_make_list();
    for(int i = 0; i < 7; i++) 
        intCLL_insert(intCLL_create_node(i), cll);
    intCLL_display(cll);
    intCLL_delete(intCLL_create_node(6), cll);
    intCLL_display(cll);
    intCLL_delete(intCLL_create_node(6), cll);
    intCLL_display(cll);
    intCLL_delete_last(cll);
    
    intCLL_insert(intCLL_create_node(1), cll);
    intCLL_insert_after(intCLL_create_node(1), intCLL_create_node(6), cll);
    intCLL_insert_before(intCLL_create_node(1), intCLL_create_node(6), cll);
    intCLL_display(cll);
    intCLL_insert_first(intCLL_create_node(10), cll);
    intCLL_display(cll);
    intCLL_delete_first(cll);
    intCLL_display(cll);
    intCLL_delete_last(cll);
    intCLL_display(cll);
    intCLL_destroy(cll);
    intCLL_display(cll);

    return 0;
}