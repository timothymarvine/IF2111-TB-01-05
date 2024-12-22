#ifndef MENU_H
#define MENU_H

typedef struct {
    char contents[10];
    int length;
} Set;

void WelcomeMenu();

void LoginMenu();

void helpinwelcome();

void helpinlogin();

void helpinmain();

void MainMenu();
#endif