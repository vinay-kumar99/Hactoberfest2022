import java.io.*;
class QueueProg
{
	public static int n=5;
	public static int front=-1, rear=-1;
	public static int arr[]=new int[n];

	void insert(int no)
	{
		if(rear == n-1)
		{
			System.out.println("Queue Overflow");
		}
		else
		{
			if(front==-1)
			{
				front = 0;
			}
			rear = rear + 1;
			arr[rear] = no;
			System.out.println("Element Inserted!!!!");
		}
	}
	void delete()
	{
		if(front>rear)
		{
			System.out.println("Queue Underflow");
		}
		else
		{
			front = front + 1;
			System.out.println("Element Deleted!!!!");
		}
	}
	void display()
	{
		System.out.println("FRONT");
		for(int i=front;i<=rear;i++)
		{
			System.out.println(arr[i]);
		}
		System.out.println("REAR");
	}
	public static void main(String args[])throws IOException
	{
		System.out.println("Queue");
		System.out.println("*****");
		QueueProg ob=new QueueProg();
		InputStreamReader isr=new InputStreamReader(System.in);
		BufferedReader br=new BufferedReader(isr);
		int no;
		int choice;
		while(true)
		{
			System.out.println("");
			System.out.println("1: INSERTION\n2: DELETION\n3: DISPLAY\n4: EXIT");
			System.out.println("");
			System.out.print("Enter Choice : ");
			choice = Integer.parseInt(br.readLine());
			System.out.println("");
			if(choice==1)
			{
				System.out.print("Enter Number to be Inserted : ");
				no = Integer.parseInt(br.readLine());
				System.out.println("");
				ob.insert(no);
			}
			else if(choice==2)
			{
				ob.delete();
			}
			else if(choice==3)
			{
				ob.display();
			}
			else if(choice==4)
			{
				break;
			}
		}
	}
}