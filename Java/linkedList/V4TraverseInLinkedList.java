package File12_LinkedLists;

public class V4TraverseInLinkedList {
    
    // inner class
    private class Node{
        int data;
        Node next;
    }

    private Node head;
    private Node tail;
    private int size;

    public void display(){

        // temp variable of Node class type storing the address of head node
        Node temp = this.head;

        while(temp!=null){

            // printing the node's data
            System.out.print("data : " + temp.data);

            // updating/incrementing the temp to point towards next node
            temp = temp.next;
        }

    }
    public static void main(String[] args) {
        
    }
}
