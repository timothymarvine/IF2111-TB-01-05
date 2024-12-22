#ifndef RLL_H
#define RLL_H

#include "load.h"
#include "ADT\definitions.h"

typedef struct {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} UserData;

typedef struct {
    UserData users[MAX_USERS];
    int totalUsers;
    char activeUser[MAX_LENGTH];
} System;

void initializeSystem(System *sys);

int isUsernameTaken(System *sys, const char *username, User user[]);

void registerUser(System *sys, const char *username, const char *password, User user[]);

int findUser(System *sys, const char *username, const char *password, User user[]);

void loginUser(System *sys, const char *username, const char *password, int *loggedIn, User user[]);

void logoutUser(System *sys, int *isLoggedIn);

#endif