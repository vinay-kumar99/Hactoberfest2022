#include <stdio.h>
#define s 20
struct queue
{
	int a[s];
	int f, r;
};
void incq(struct queue *q)
{
	q->f = 0;
	q->r = 0;
}
int en(struct queue *q, int x)
{
	if ((q->r + 1) % s == q->f)
	{
		printf("!Error:Queue is Full!\n");
		return 1;
	}
	else
	{
		q->a[q->r] = x;
		q->r = (q->r + 1) % s;
		printf("!%d added in Queue!\n", x);
	}
}
int de(struct queue *q)
{
	if (q->r == q->f)
	{
		printf("!Error:Queue is Empty!\n");
		return -1;
	}
	else
	{
		int x = q->a[q->f];
		q->f = (q->f + 1) % s;
		printf("!%d deleted from queue!\n", x);
		return (x);
	}
}
void display(struct queue q)
{
	if (q.f == q.r)
	{
		printf("!Error:Queue is Empty!\n");
		return;
	}
	int i = q.f;
	while (i != q.r)
	{
		printf("%d\t", q.a[i]);
		i = (i + 1) % s;
	}
	printf("\n");
}
int main()
{
	struct queue q;
	int o, p;
	incq(&q);
	printf("Queue Operations:\n");
	do
	{

		printf("1.Enqueue(Insert Element in queue)\n");
		printf("2.Dequeue(Delete Element from queue)\n");
		printf("3.Display Circular Queue\n");
		printf("4.!Exit!\n");
		printf("Choose option(1-4):");
		scanf("%d", &o);
		switch (o)
		{
		case 1:
			printf("Enter element to add in queue:");
			scanf("%d", &p);
			en(&q, p);
			break;
		case 2:
			de(&q);
			break;
        case 3:
			printf("Display Queue:\n");
			display(q);
			break;
		case 4:
			printf("!Exit!\n");
			break;
		default:
			printf("Error:Invalid option\n");
		}
	} while (o != 4);
	return 0;
}
