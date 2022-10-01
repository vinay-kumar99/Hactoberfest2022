package File12_LinkedLists;

// we can create a class for Node like this but this class will be accessable to all the classes present in this package
// class Node{
//     int data;
//     Node next;
// }

// we don't want this class to be accessable to other classes of this package because this is exclusively for Linked List
// SO, we will make this class as innner private class so that it will be accessable to linked list only

public class V3ImplementationofLL {

    // inner class
    // the properties of Node class are data and next
    private class Node{
        int data;
        Node next;
    }

    
    // Properties of Linked List class
    private Node head;
    private Node tail;
    private int size;


    public static void main(String[] args) {
        
    }
}
