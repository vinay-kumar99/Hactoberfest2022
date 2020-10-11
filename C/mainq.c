#include <stdio.h>
 
#define MAX 50
int q[MAX];
int rear = - 1;
int front = - 1;
void insert()
{
    int add_item;
    if (rear == MAX - 1)
    printf("Queue Overflow \n");
    else
    {
        if (front == - 1)
        front = 0;
        printf("Inset the element in queue : ");
        scanf("%d", &add_item);
        rear = rear + 1;
        q[rear] = add_item;
    }
}
 
void delete()
{
    if (front == - 1 || front > rear)
    {
        printf("Queue Underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", q[front]);
        front = front + 1;
    }
}
void display()
{
    int i;
    if (front == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", q[i]);
        printf("\n");
    }
}
void main()
{
    int choice;
    printf("1.Insert element to queue \n");
    printf("2.Delete element from queue \n");
    printf("3.Display all elements of queue \n");
    printf("4.Quit \n");
    do
    {
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            insert();
            break;
            case 2:
            delete();
            break;
            case 3:
            display();
            break;
            case 4:
            printf("EXIT");
        }
    }while(choice!=4);
} 
/* ""OUTPUT""
1.Insert element to queue
2.Delete element from queue
3.Display all elements of queue
4.Quit
Enter your choice : 1
Inset the element in queue : 10
Enter your choice : 1
Inset the element in queue : 20
Enter your choice : 1
Inset the element in queue : 30
Enter your choice : 3
Queue is :
10 20 30
Enter your choice : 2
Element deleted from queue is : 10
Enter your choice : 2
Element deleted from queue is : 20
Enter your choice : 3
Queue is :
30
Enter your choice : 4
EXIT

*/
