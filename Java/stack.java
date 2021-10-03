// Program to implemet Stack in java.

import java.io.DataInputStream;
import java.io.IOException;

class stack_operations
{
	int stack[] = new int[10];
	int TOP = -1;

	DataInputStream dis = new DataInputStream(System.in);

	public void insert_operation() throws IOException
	{
		int a;
		if(TOP == 9)
		{
			System.out.println("STACK OVERFLOW");
		}
		else
		{
			System.out.println("ENTER THE ELEMENT WHICH YOU WANT TO INSERT :");
			a = Integer.parseInt(dis.readLine());
			TOP++;
			stack[TOP] = a;
		}
	}

	public void remove_operation() throws IOException
	{
		int a;
		if(TOP == -1)
		{
			System.out.println("STACK UNDERFLOW");
		}
		else
		{
			System.out.print("REMOVED TOP ELEMENT FROM THE STACK IS : " +stack[TOP]);
			TOP--;
		}
	}

	public void display_operation() throws IOException
	{
		int i;
		if(TOP == -1)
		{
			System.out.println("STACK IS EMPTY, NOTHING TO DISPLAY");
		}
		else
		{
			System.out.println("STACK CONTAINS");
			for(i=TOP;i>=0;i--)
			{
				System.out.println(stack[i]);
			}
		}
	}
}

class stack
{
	public static void main(String arr[]) throws IOException
	{
		int ch;
		stack_operations s = new stack_operations();

		DataInputStream dis = new DataInputStream(System.in);

		do
		{
			System.out.println("\n1 - INSERT");
			System.out.println("2 - REMOVE");
			System.out.println("3 - DISPLAY");
			System.out.println("4 - EXIT");

			System.out.print("PROVIDE YOUR CHOICE :");
			ch = Integer.parseInt(dis.readLine());

			switch(ch)
			{
				case 1: s.insert_operation();
				break;

				case 2: s.remove_operation();
				break;

				case 3: s.display_operation();
				break;

				case 4: System.exit(0);
				break;

				default: System.out.println("INVALID CHOICE");
			}
		}while(ch!=0);
	}
}