#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(void) {
    IntLinkedList *ll = intLL_make_list();
    // printf("%d\n", intLL_is_empty(ll));
    // for(int i = 1; i < 7; i++)
    //     intLL_insert(intLL_create_node(i), ll);
    // intLL_display(ll);
    // intLL_insert(intLL_create_node(2), ll);
    // intLL_insert_before(
    //     intLL_create_node(2),
    //     intLL_create_node(29),
    //     ll
    // );
    // intLL_display(ll);
    // printf("%d\n", intLL_is_empty(ll));

    intLL_insert(intLL_create_node(2), ll);
    intLL_display(ll);
    intLL_delete(
        intLL_create_node(2), 
        ll
    );
    intLL_display(ll);
    intLL_insert(intLL_create_node(2), ll);
    intLL_delete_first(ll);
    intLL_display(ll);
    intLL_insert(intLL_create_node(2), ll);
    intLL_delete_last(ll);
    intLL_display(ll);

    

}