import java.io.*;
class StackProg
{
	public static int n=5;
	public static int top=-1;
	public static int arr[]=new int[n];

	void push(int no)
	{
		if(top == n-1)
		{
			System.out.println("Stack Overflow");
		}
		else
		{
			top = top + 1;
			arr[top] = no;
			System.out.println("Element Pushed!!!!");
		}
	}
	void pop()
	{
		if(top == -1)
		{
			System.out.println("Stack Underflow");
		}
		else
		{
			top = top - 1;
			System.out.println("Element Popped!!!!");
		}
	}
	void peep(int pos)
	{
		if(top-pos+1 <= 0)
		{
			System.out.println("Stack Underflow");
		}
		else
		{
			System.out.println("Peeped Element : "+arr[top-pos+1]);
		}
	}
	void change(int pos, int no)
	{
		if(top-pos+1 <= 0)
		{
			System.out.println("Stack Underflow");
		}
		else
		{
			arr[top-pos+1] = no;
		}
	}
	void display()
	{
		System.out.println("STACK");
		for(int i=top; i>=0; i--)
		{
			System.out.println(arr[i]);
		}
	}
    public static void main(String args[]) throws IOException
    {
        System.out.println("STACK");
        System.out.println("******");
        InputStreamReader isr=new InputStreamReader(System.in);
        BufferedReader br=new BufferedReader(isr);
        StackProg ob=new StackProg();
        int no,newNum;
        int pos1,pos2;
		int choice;
		while(true)
		{
			System.out.println("");
			System.out.println("1: PUSH\n2: POP\n3: PEEP\n4: CHANGE\n5: DISPLAY\n6: EXIT");
			System.out.println("");
			System.out.print("Enter Choice : ");
			choice = Integer.parseInt(br.readLine());
			System.out.println("");
			if(choice==1)
			{
				System.out.print("Enter Number to be Pushed : ");
				no = Integer.parseInt(br.readLine());
				System.out.println("");
				ob.push(no);
			}
			else if(choice==2)
			{
				ob.pop();
			}
			else if(choice==3)
			{
				System.out.println("Enter the Position of Element to Peep : ");
				pos1 = Integer.parseInt(br.readLine());
				System.out.println("");
				ob.peep(pos1);
			}
			else if(choice==4)
			{
				System.out.print("Enter the New Number : ");
				newNum = Integer.parseInt(br.readLine());
				System.out.print("Enter the Position of Element to be Changed : ");
				pos2 = Integer.parseInt(br.readLine());
				System.out.println(""); 
				ob.change(pos2, newNum);
			}
			else if(choice==5)
			{
				ob.display();
			}
			else if(choice==6)
			{
				break;
			}
		}
	}
}