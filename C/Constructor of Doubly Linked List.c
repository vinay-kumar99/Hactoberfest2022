#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node Node;
Node *head,*newnode;
void create(){
    head = 0;
    Node *temp;
    int choice = 1;
    while(choice != 0){
        newnode = (Node*) malloc(sizeof(Node));
        printf("Enter data for Doubly Linked List: ");
        scanf("%d",&newnode->data);
        newnode->prev = 0;
        newnode->next = 0;
        if(head == 0){
            head =  temp = newnode;
        }
        else{
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
        printf("Do you wanna continue(1 or 0)?");
        scanf("%d",&choice);
    }
    temp->next = 0;
}
void display(){
    Node *temp;
    temp = head;
    while(temp!= 0){
        printf("%d==>",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main(){
    create();
    display();
    return 0;
}
