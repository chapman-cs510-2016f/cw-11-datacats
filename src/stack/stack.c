#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

STACK new_stack() {
    STACK new = NULL;
    return new;
}

void push_stack(STACK *s, SVALUE val) {
    STACK new = (STACK) malloc(sizeof(struct stack));
    new->data = val;
    new->head = *s;
    *s = new;
}

SVALUE pop_stack(STACK *s) {
    SVALUE val;
    STACK temp;
    if (*s == NULL) {
      val = -1;
    }
    else {
      val = (*s)->data;
      temp = (*s);
      *s = (*s)->head;
      free(temp);
    }
    return val;
}

// prints the value passed in, of type SVALUE
void print_svalue(SVALUE a) {
    printf ("%d", a);
}

// takes in a stack b
void print_stack(STACK b) {
    // calls the print_svalue and passes stack b's data value to be printed
    // also prints a new line afterwards.
    print_svalue(b->data);
    printf("\n");
    
    // if stack b's head points to nothing, the function will end. 
    // Otherwise, recursively calls the print_stack function
    // passing in stack b's head, which points to the next element of the "stack"
    if (b->head == NULL){
        return;
    }
    print_stack(b->head);
}


