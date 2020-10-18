#include <stdio.h>
//#include <bits/stdc++.h>
#define N 5
int queue[N];
int front = -1;
int rear = -1;
void enqueue(int x)
{
    if (rear == N - 1)
    {
        printf("Overflow");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else
    {
        rear++;
        queue[rear] = x;
    }
}
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Underflow");
    }
    else if (rear == front)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
}
void display()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is Empty");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
}
void peek()
{
    if (front == -1 && rear == -1)
    {
        printf("Under flow");
    }
    else
    {
        printf(" \n The First element of the Queue is %d", queue[front]);
    }
}
int main()
{
    int choice;
    do
    {
        printf("\n..................................................MENU...............................................");
        printf("\n1.To enter element in the queue...");
        printf("\n2.To remove an element from the Queue...");
        printf("\n3.To check the first element of the queue....");
        printf("\n4.To display element of the Queue...");
        printf("\n......................\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter element you want to enter: ");
            int x;
            scanf("%d", &x);
            enqueue(x);
            break;
        case 2:
            dequeue();
            printf("Element Removed\n");
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;

        default:
            break;
        }
    } while (choice != 0);
}
