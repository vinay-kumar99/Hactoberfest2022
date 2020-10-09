#include<stdio.h>
#define N 10
int top=-1,x,i;
int s[N];
void push();
void pop();
void display();
void push()
{
	if(top>=N-1)
	{
		printf("Stack is full");
	}
	else
	{
		printf("Enter element = ");
		scanf("%d",&x);
		top++;
		s[top]=x;
	}
}
void pop()
{
	if(top<=-1)
	{
		printf("Stack is empty");
	}
	else
	{
		printf("The popped element is = %d",s[top]);
		top--;
	}
}
void display()
{
	if(top>=0)
	{
		for(i=top;i>=0;i--)
		{
			printf("%d\n",s[i]);
		}
	}
	else
	{
		printf("Stack is empty");
	}
}
void main()
{
	int ch;
	printf("\n 1.PUSH \t\n 2.POP \t\n 3.DISPLAY \t\n 4.EXIT \t\n");
	do
	{
		printf("\n Enter choice = ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("EXIT");
		}	
	}while(ch!=4);
}

/*  ""OUTPUT""

 1.PUSH
 2.POP
 3.DISPLAY
 4.EXIT

 Enter choice = 1
Enter element = 10

 Enter choice = 1
Enter element = 20

 Enter choice = 1
Enter element = 30

 Enter choice = 3
30
20
10

 Enter choice = 2
The popped element is = 30
 Enter choice = 2
The popped element is = 20
 Enter choice = 3
10

 Enter choice = 4
EXIT

*/
