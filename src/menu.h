#ifndef MENU_H
#define MENU_H

typedef struct {
    char contents[10];
    int length;
} Set;

int manual_strcmp(char *str1, char *str2);

void WelcomeMenu();

void LoginMenu();

void helpinwelcome();

void helpinlogin();

void helpinmain();

void MainMenu();
#endif