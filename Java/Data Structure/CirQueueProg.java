import java.io.*;
class CirQueueProg
{
	public static int front=-1, rear=-1;
	public static int n=5;
	public static int arr[] = new int[n];

	void insert(int no)
	{
		if(front==0 && rear==(n-1) || front==rear+1)
		{
			System.out.println("Queue Overflow");
		}
		else
		{
			if(front==-1)
			{
				front = 0;
			}
			rear = (rear + 1)%n;
			arr[rear] = no;
			System.out.println("Element Inserted!!!!");
		}
	}
	void delete()
	{
		if(front==-1 && rear==-1)
		{
			System.out.println("Queue Underflow");
		}
		else
		{
			if (front == rear)
			{
		        front = -1;
		       	rear = -1;
	        }
	        else
	        {
	        	front = (front + 1)%n;
				System.out.println("Element Deleted!!!!");
	        }  
		}
	}
	void display()
	{
		int i;
		System.out.println("FRONT");
		for(i=front; ;i=(i+1)%n)
		{
			System.out.println(arr[i]);
			if(i==rear)
			{
				break;
			}
		}
		System.out.println("REAR");
	}
	public static void main(String args[]) throws IOException 
	{
		System.out.println("Circular Queue");
		System.out.println("**************");
		InputStreamReader isr=new InputStreamReader(System.in);
		BufferedReader br=new BufferedReader(isr);
		CirQueueProg ob=new CirQueueProg();
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