// Program to implement Queue in java.

import java.io.DataInputStream;
import java.io.IOException;

class queue_operation
{
	int queue[] = new int[10];
	int REAR = -1;
	int FRONT = 0;

	DataInputStream dis = new DataInputStream(System.in);

	public void insert_operation() throws IOException
	{
		int a;
		if(REAR == 9)
		{
			System.out.println("QUEUE OVERFLOW");
		}
		else
		{
			System.out.print("ENTER RLRMRNT WHICH YOU WANT TO INSERT :");
			a = Integer.parseInt(dis.readLine());

			queue[REAR+1] = a;
			REAR++;
		}
	}

	public void remove_operation()
	{
		int a;
		if(FRONT == (REAR+1))
		{
			System.out.println("QUEUE UNDERFLOW");
		}
		else
		{
			System.out.println("REMOVED ELEMENT FROM QUEUE " +queue[FRONT]);
			FRONT++;
		}
	}

	public void display_operation()
	{
		int i;
		if(FRONT == (REAR+1))
		{
			System.out.println("QUEUE IS EMPTY, NOTHING TO DISPLAY");
		}
		else
		{
			System.out.println("QUEUE CONTAINS");
			for(i=FRONT;i<=REAR;i++)
			{
				System.out.print(queue[i]+ "\t");
			}
		}
	}
}

class queue
{
	public static void main(String arr[]) throws IOException
	{
		int ch;
		queue_operation q = new queue_operation();
		DataInputStream dis = new DataInputStream(System.in);

		do
		{
			System.out.println("\n1 - INSERT");
			System.out.println("2 - REMOVE");
			System.out.println("3 - DISPLAY");
			System.out.println("4 - EXIT");

			System.out.println("PROVIDE YOUR CHOICE :");
			ch = Integer.parseInt(dis.readLine());

			switch(ch)
			{
				case 1: q.insert_operation();
				break;

				case 2: q.remove_operation();
				break;

				case 3: q.display_operation();
				break;

				case 4: System.exit(0);
				break;

				default: System.out.println("INVALID CHOICE");
			}
		}
		while(ch!=0);
	}
}