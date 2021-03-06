#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(void) {
    IntLL *ll = intLL_make_list();
    for(int i = 0; i < 7; i++) {
        intLL_insert(intLL_create_node(i), ll);
    }
    intLL_insert_last(intLL_create_node(10), ll);
    intLL_display(ll);
    intLL_insert_after(intLL_create_node(2), intLL_create_node(5), ll);
    intLL_insert_before(intLL_create_node(2), intLL_create_node(5), ll);
    intLL_display(ll);

    intLL_delete(intLL_create_node(10), ll);
    intLL_display(ll);
    
    intLL_delete_first(ll);
    intLL_display(ll);

    intLL_delete_last(ll);
    intLL_display(ll);

    intLL_destroy(ll);
    intLL_display(ll);

    return 0;
}