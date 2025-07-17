//
// Created by dudan on 17/07/2025.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 100

typedef struct Node {
    char text[MAX_LEN];
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

int main(void) {
    int choice ;
    do {
        printf("----- CLIPBOARD MANAGER ------ \n ");
        printf(" 1. COPY \n ");
        printf(" 2. PASTE \n ");
        printf(" 3. UNDO \n ");
        printf(" 4. REDO \n ");
        printf(" 5. PRINT \n ");
        printf(" 6. EXIT \n ");
        scanf("%d ", &choice);
        switch (choice) {
            case 1 :
                break;
            case 2 :
                break;
            case 3 :
                break ;
            case 4 :
                break ;
            case 5 :
                break;
            case 6 :
                printf(" EXIT PROGRAMS  ");
        }
    }while (choice != 6);

    return 0;
}