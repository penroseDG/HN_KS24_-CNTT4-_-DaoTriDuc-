//
// Created by dudan on 17/07/2025.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Project {
    int id ;
    char title [100] ;
    char owner[100] ;
    int priority ;
    struct Project *next ;
} Project ;
typedef struct DoneProject {
    int id ;
    char title [100] ;
    char owner[100] ;
    int priority ;
    struct DoneProject *next;
    struct DoneProject *prev ;
} DoneProject ;

Project* head = NULL ;
DoneProject* doneHead = NULL ;

Project* createProject( int id,char title[],char owner[],int priority ){
       Project* newProject = ( Project* ) malloc ( sizeof ( Project ) ) ;
       newProject -> id = id ;
       strcpy ( newProject -> title , title ) ;
       strcpy ( newProject -> owner , owner ) ;
       newProject -> priority = priority ;
       newProject -> next = NULL ;
   return newProject ;
}
DoneProject* createDoneProject( int id , char title[],char owner[],int priority ) {
    DoneProject* newProject = ( DoneProject* ) malloc ( sizeof ( DoneProject ) ) ;
    newProject -> id = id ;
    strcpy ( newProject -> title , title ) ;
    strcpy ( newProject -> owner , owner ) ;
    newProject -> priority = priority ;
    newProject -> next = NULL ;
    newProject -> prev = NULL ;
    return newProject ;
}
void addProject() {
    int id , priority ;
    char title[100] , owner[100] ;
    printf("Nhap id du an  : \n");
    scanf("%d" , &id );
    getchar();
    printf("Nhap ten du an  : \n ");
    gets(title);
    printf("Nhap nguoi lam du an  : \n ");
    gets(owner);
    printf(" Nhap do uu tien du an  : \n");
    scanf("%d",&priority);
    Project* newProject = createProject( id,title,owner,priority );
    newProject -> next = head ;
    head = newProject ;
    // reuturn head = newProject ;
}

void showProjects() {
    Project* temp = head;
    while (temp) {
        printf("|%d | %s | %s | %d\n", temp->id, temp->title, temp->owner, temp->priority);
        temp = temp->next;
    }
}

void deleteProject() {
    int id;
    printf("Nhap id du an  : \n");
    scanf("%d", &id);
    Project *temp = head, *prev = NULL;
    while (temp && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) return;
    if (!prev) head = head->next;
    else prev->next = temp->next;
    free(temp);
}

void updateProject() {
    int id;
    printf("Nhap id du an  : \n");
    scanf("%d", &id);
    getchar();
    Project* temp = head;
    while (temp && temp->id != id) temp = temp->next;
    if (!temp) return;
    printf("Nhap ten du an : \n ");
    gets(temp->title);
    printf("Nhap nguoi lam du an :\n");
    gets(temp->owner);
    printf("Nhap do uu tien du an  : \n");
    scanf("%d", &temp->priority);
}

void sortProjects() {
    Project *i, *j;
    for (i = head; i; i = i->next) {
        for (j = i->next; j; j = j->next) {
            if (i->priority > j->priority) {
                int id = i->id;
                char title[100], owner[100];
                int priority = i->priority;
                strcpy(title, i->title);
                strcpy(owner, i->owner);
                i->id = j->id;
                strcpy(i->title, j->title);
                strcpy(i->owner, j->owner);
                i->priority = j->priority;
                j->id = id;
                strcpy(j->title, title);
                strcpy(j->owner, owner);
                j->priority = priority;
            }
        }
    }
}
void searchByName() {
    char name[100];
    getchar();
    printf("Nhap ten du an : \n");
    gets(name);
    Project *temp = head ;
    while (temp) {
        if (strcmp(temp->title, name) == 0)
            printf("|%d | %s | %s | %d\n", temp->id, temp->title, temp->owner, temp->priority);
            temp = temp->next;

    }
}
int main(void){
    int choice;
    do {
        printf("----- PROJECT MANAGER ----- \n");
        printf("1. Them moi du an  \n");
        printf("2. Hien thi du an  \n");
        printf("3. Xoa du an  \n");
        printf("4. Cap nhat du an   \n");
        printf("5. Danh dau du an hoan thanh  \n");
        printf("6. Sap xep du an theo tien do uu tien  \n");
        printf("7. Tim kiem du an theo ten  \n");
        printf("8. Thoat \n");
        scanf("%d" , &choice);
        switch (choice) {
            case 1 :
                addProject();
                break;
            case 2 :
                showProjects();
                break;
            case 3 :
                deleteProject();
                break;
            case 4 :
              updateProject();
                break;
            case 5 :

                break;
            case 6 :
                sortProjects();
                break;
            case 7:
                searchByName();
                break;
            case 8:
                printf("Thoat chuong trinh  ");

        }
    }while(choice !=8);
return 0 ;
}