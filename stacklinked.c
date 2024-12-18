#include <stdio.h>
#include <stdlib.h>
#include "stacklinked.h"

/* Prototype manajemen memori */
Address newNode(ElType x) {
    Address p = (Address) malloc(sizeof(Node));
    if (p != NULL) { // Ganti NIL dengan NULL
        INFO(p) = x;
        NEXT(p) = NULL;
    }
    return p;
}

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/

boolean isEmpty(Stack s) {
    return ADDR_TOP(s) == NULL; // Ganti NIL dengan NULL
}

int length(Stack s) {
    int count = 0;
    Address p = ADDR_TOP(s);
    while (p != NULL) { // Ganti NIL dengan NULL
        count++;
        p = NEXT(p);
    }
    return count;
}

void CreateStack(Stack *s) {
    ADDR_TOP(*s) = NULL; // Ganti NIL dengan NULL
}

void DisplayStack(Stack s) {
    Address p = ADDR_TOP(s);
    printf("[");
    while (p != NULL) { // Ganti NIL dengan NULL
        printf("%s", INFO(p).itemName); // Asumsikan INFO(p) adalah Purchase
        if (NEXT(p) != NULL) {
            printf(", ");
        }
        p = NEXT(p);
    }
    printf("]\n");
}

void push(Stack *s, ElType x) {
    Address p = newNode(x);
    if (p != NULL) {
        NEXT(p) = ADDR_TOP(*s);
        ADDR_TOP(*s) = p;
    }
}

void pop(Stack *s, ElType *x) {
    if (!isEmpty(*s)) {
        Address p = ADDR_TOP(*s);
        *x = INFO(p);
        ADDR_TOP(*s) = NEXT(p);
        free(p);
    }
}
