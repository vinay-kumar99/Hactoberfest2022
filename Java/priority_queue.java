// program to implement Priority Queue in java.

import java.io.DataInputStream;
import java.io.IOException;

class p_queue_operation
{
	int p_queue[] = new int[20];
	int REAR = -1;

	DataInputStream dis = new DataInputStream(System.in);

	public void insert_operation() throws IOException
	{
		int a;
		if(REAR == 19)
		{
			System.out.println("PRIORITY QUEUE OVERFLOW");
		}
		else
		{
			System.out.println("ENTER ELEMENT THAT YOU WANT TO INSERT :");
			a = Integer.parseInt(dis.readLine());

			p_queue[REAR+1] = a;
			REAR++;
		}
	}

	public void remove_operation()
	{
		int a, i, j, temp;
		if(REAR == (-1))
		{
			System.out.println("PRIORITY QUEUE UNDERFLOW");
		}
		else
		{
			for(i=0;i<REAR;i++)
			{
				for(j=(i+1);j<=REAR;j++)
				{
					if(p_queue[i] > p_queue[j])
					{
						temp = p_queue[i];
						p_queue[i] = p_queue[j];
						p_queue[j] = temp;
					}
				}
			}
			System.out.println("REMOVED PRIORITY ELEMENT IS : " + p_queue[0]);

			for(i=0;i<REAR;i++)
			{
				p_queue[i] = p_queue[i+1];
			}
			REAR--;
		}
	}

	public void display_operation()
	{
		int i;
		if(REAR == (-1))
		{
			System.out.println("PRIORITY QUEUE IS EMPTY, NOTHING TO DISPLAY");
		}
		else
		{
			System.out.println("PRIORITY QUEUE CONTAINS :");
			for(i=0;i<=REAR;i++)
			{
				System.out.print(p_queue[i]+ "\t");
			}
		}
	}
}


class priority_queue
{
	public static void main(String arr[]) throws IOException
		{
			int ch;
			p_queue_operation p = new p_queue_operation();
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
					case 1: p.insert_operation();
					break;

					case 2: p.remove_operation();
					break;

					case 3: p.display_operation();
					break;

					case 4: System.exit(0);
					break;

					default: System.out.println("INVALID CHOICE");
				}
			}
			while(ch!=0);
	}
}