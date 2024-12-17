#include "stack.h"

void CreateEmptyStack(Stack *S) {
    S->TOP = Nil;
}

boolean IsEmptyStack(Stack S) {
    return S.TOP == Nil;
}

boolean IsFullStack(Stack S) {
    return S.TOP == CAPACITY - 1;
}

void Push(Stack *S, infotypeStack X) {
    if (!IsFullStack(*S)) {
        S->TOP++;
        S->T[S->TOP] = X;
    }
}

void Pop(Stack *S, infotypeStack *X) {
    if (!IsEmptyStack(*S)) {
        *X = S->T[S->TOP];
        S->TOP--;
    }
}
