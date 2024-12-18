#ifndef __WISHLISTCONSOLE_H__
#define __WISHLISTCONSOLE_H__

#include <stdio.h>
#include "boolean.h"
#include "linkedlist.h"
#include "string.h"
#include "mesinkata.h"
#include "mesinkarakter.h"

int MyStrLen(const char *str);

void MyStrCpy(char *dest, const char *src);

int MyStrCmp(const char *str1, const char *str2);

int IsBarangValid(const char *NamaBarang);

void wishlistAdd(LinkedList *L);

void wishlistSwap(LinkedList *L, int i, int j);

void wishlistRemoveIndex(LinkedList *L, int index);

void wishlistRemove(LinkedList *L);

void wishlistClear(LinkedList *L);

void wishlistShow(LinkedList L);

#endif