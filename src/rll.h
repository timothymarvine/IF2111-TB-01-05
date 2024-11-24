#ifndef RLL_H
#define RLL_H

#define MAX_USERS 100
#define MAX_LENGTH 100
typedef struct {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} User;

typedef struct {
    User users[MAX_USERS];
    int totalUsers;
    char activeUser[MAX_LENGTH];
} System;

void initializeSystem(System *sys);

int isUsernameTaken(System *sys, const char *username);

void registerUser(System *sys, const char *username, const char *password);

int findUser(System *sys, const char *username, const char *password);

void loginUser(System *sys, const char *username, const char *password, int *loggedIn);

void logoutUser(System *sys, int *isLoggedIn);

#endif