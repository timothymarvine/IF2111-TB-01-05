#include "start.h"
#include "load.h"
#include <stdio.h>

void ConfigReader(int *itemCtr, int *userCtr, User sys[], Barang list[]){
    LOAD("config.txt", list, *itemCtr, sys, userCtr);
}