// Program to implement DE-Queue in java.

import java.io.DataInputStream;
import java.io.IOException;

class de_queue_operation
{
	int de_queue[] = new int[20];
	int REAR = 0;
	int FRONT = -1;
	DataInputStream dis = new DataInputStream(System.in);

	public void insert_from_rear() throws IOException
	{
		int a;
	}

	public void insert_from_front() throws IOException
	{
		int a;
		if(FRONT == 0)
		{
			System.out.println("DEQUEUE OVERFLOW");
		}
		else
		{
			System.out.println("ENTER ELEMENT THAT YOU WANT TO INSERT FROM FRONT :");
			a = Integer.parseInt(dis.readLine());

			de_queue[FRONT-1] = a;
			FRONT--;
		}
	}

	public void remove_from_rear()
	{
		int a;
		if(FRONT == REAR)
		{
			System.out.println("DEQUEUE UNDERFLOW");
		}
		else
		{
			System.out.print("REAR REMOVED ELEMENT IS : " + de_queue[REAR-1]);
			REAR--;
		}
	}

	public void remove_from_front()
	{
		int a;
		if(FRONT == REAR)
		{
			System.out.println("DEQUEUE UNDERFLOW");
		}
		else
		{
			System.out.println("FRONT REMOVED ELEMENT IS : " + de_queue[FRONT]);
			FRONT++;
		}
	}

	public void display_operation()
	{
		int i;
		if(FRONT >= REAR)
		{
			System.out.println("DEQUEUE IS EMPTY, NOTHING TO DISPLAY");
		}
		else
		{
			System.out.println("DEQUEUE CONATAINS");
			for(i=FRONT;i>=REAR;i++)
			{
				System.out.println(de_queue[i] + "\t");
			}
		}
	}
}

class de_queue
{
	public static void main(String arr[]) throws IOException
	{
		int ch;
		de_queue_operation q = new de_queue_operation();
		DataInputStream dis = new DataInputStream(System.in);

		do
		{
			System.out.println("\n1 - INSERT FROM REAR");
			System.out.println("2 - INSERT FROM FRONT");
			System.out.println("3 - REMOVE FROM REAR");
			System.out.println("4 - REMOVE FROM FRONT");
			System.out.println("5 - DISPLAY");
			System.out.println("6 - EXIT");

			System.out.println("PROVIDE YOUR CHOICE :");
			ch = Integer.parseInt(dis.readLine());

			switch(ch)
			{
				case 1: q.insert_from_rear();
				break;

				case 2: q.insert_from_front();
				break;

				case 3: q.remove_from_rear();
				break;

				case 4: q.remove_from_front();
				break;

				case 5: q.display_operation();
				break;

				case 6: System.exit(0);
				break;

				default: System.out.println("INVALID CHOICE");
			}
		}
		while(ch!=0);
	}
}