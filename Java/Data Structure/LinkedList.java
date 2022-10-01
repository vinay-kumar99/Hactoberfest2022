import java.io.*;
class LinkedList
{
	Node head;

	void insert(int data)
	{
		Node node = new Node();
		node.data = data;
		node.next = null;

		if(head==null)
		{
			head = node;
		}
		else
		{
			Node n = head;
			while(n.next!=null)
			{
				n = n.next;
			}
			n.next = node;
		}
	}
	void display()
	{
		Node n = head;
		while(n.next!=null)
		{
			System.out.print(n.data+"->");
			n = n.next;
		}
		System.out.print(n.data);
	}
	public static void main(String args[]) throws IOException
	{
		System.out.println("Linked List");
		System.out.println("***********");
		System.out.println("");
		InputStreamReader isr=new InputStreamReader(System.in);
		BufferedReader br=new BufferedReader(isr);
		LinkedList ob = new LinkedList();

		ob.insert(5);
		ob.insert(6);
		ob.insert(7);
		ob.insert(8);
		ob.display();
	}
}