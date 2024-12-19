#ifndef MAINADT_H
#define MAINADT_H

#include "datatype.h"
#include "..\map\map.h"
#include "..\stack\stack.h"
#include "..\linkedlist\linkedlist.h"

typedef struct {
    char name[MAX_STRLEN];
    char password[MAX_STRLEN];
    int money;
    Map cart;
    Stack history;
    LinkedList wishlist;
} UserCheckOut;

#endif