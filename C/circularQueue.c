#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define size 5
void enqueue(int n);
void dequeue();
void display();

int cQueue[size],front=-1,rear=-1;
int main()
{
    int choice, value;
   do
   {
      printf("\n*** Operations ***\n");
      printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d",&choice);
      switch(choice)
        {
	 case 1: printf("\nEnter the value to be insert:  ");
		 scanf("%d",&value);
		 enqueue(value);
		 break;
	 case 2: dequeue();
		 break;
	 case 3: display();
		 break;
	 case 4: exit(0);
	    break;
	 default: printf("\nPlease select the correct choice!!!\n");
        }
    }while(choice!=4);
   return 0;
}

void enqueue(int value)
{
   if((front == 0 && rear == size - 1) || (front == rear+1))
      printf("\nCircular Queue is Full! Insertion not possible!!!\n");
   else{
      if(rear == size-1 && front != 0)
	 rear = -1;
      cQueue[++rear] = value;
      printf("\nInsertion Success!!!\n");
      if(front == -1)
	 front = 0;
   }
}
void dequeue()
{
   if(front == -1 && rear == -1)
      printf("\nCircular Queue is Empty! Deletion is not possible!!!\n");
   else{
      printf("\nDeleted element : %d\n",cQueue[front++]);
      if(front == size)
	 front = 0;
      if(front-1 == rear)
	 front = rear = -1;
   }
}
void display()
{
   if(front == -1)
      printf("\nCircular Queue is Empty!!!\n");
   else{
      int i = front;
      printf("\nCircular Queue Elements are : \n");
      if(front <= rear){
	 while(i <= rear)
	    printf("%d\t",cQueue[i++]);
      }
      else{
	 while(i <= size - 1)
	    printf("%d\t", cQueue[i++]);
	 i = 0;
	 while(i <= rear)
	    printf("%d\t",cQueue[i++]);
      }
   }
}
