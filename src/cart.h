#ifndef CART_H
#define CART_H

#include "ADT\map\map.h"
#include "ADT\array\arraydin.h"
#include "ADT\array\array.h"
#include "ADT\kustom\datatype.h"
#include "ADT\mesinkata\mesinkata.h"

void CartAdd(Map *c, int qty, ArrayDin list, Word newItem);

void CartRemove(Map *c, int qty, Word item);

void CARTPAY(Map *cart, ArrayDin list);

void CARTSHOW(Map cart, ArrayDin list);

#endif