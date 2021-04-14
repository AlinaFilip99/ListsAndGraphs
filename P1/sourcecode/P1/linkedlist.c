#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linkedlist.h"

void push_element_end(struct g_node *head ,int new_element_value){
    struct g_node *new_element = malloc(sizeof(struct g_node));
    struct g_node *iterator = head;
    struct g_node *last_element;

    while (iterator->next != head) {
        iterator = iterator->next;
    }
    last_element = iterator;

    last_element->next = new_element;
    new_element->info = new_element_value;
    new_element->next = head;
}

int pop_element_at_position(struct g_node *head, int position){
    struct g_node *iterator;
    struct g_node *poped_element;
    struct g_node *previous_element;
    int current_position;
    int aux, a=0, i;

    assert(position >= 0);
    iterator = head;
    current_position = 0;

    while( current_position < position ){
        current_position++;
        iterator = iterator->next;
        if(iterator==head){a++;}
    }

    while((a!=0)&&(a!=1))
    {
        if(iterator->next==head)
        {iterator=iterator->next->next;
        a--;}
        else{iterator=iterator->next;
                a--;}

    }
    if(iterator->next==head)
    {
        iterator=iterator->next;
    }

    previous_element = iterator;
    poped_element = previous_element->next;
    previous_element->next = poped_element->next;
    aux = poped_element->info;
    free(poped_element);

    return aux;
}
