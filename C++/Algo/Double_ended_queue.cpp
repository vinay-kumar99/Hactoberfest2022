#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

class DEQueue_Class
{
    Node *front = NULL;
    Node *rear = NULL;
    Node *ptr;

protected:
    bool isEmpty();
    void reset_Pos();

public:
    void Insert_in_the_queue(); // done
    void Enqueue_from_front();  // done
    void Enqueue_from_rear();   // done
    void Dequeue_from_front();  // done
    void Dequeue_from_rear();
    void display();
};

void DEQueue_Class::Dequeue_from_rear()
{
    Node *temp = front;
    Node *delNode = rear;
    if (isEmpty())
    {
        cout << "The queue is Empty!!!!";
    }
    else
    {
        while (temp->next != rear)
        {
            temp = temp->next;
        }
        rear = temp;
        rear->next=NULL;
        delete delNode;
    }
    cout << endl;
}
void DEQueue_Class::Dequeue_from_front()
{
    if (isEmpty())
    {
        cout << "The queue is Empty!!!!!";
    }
    else
    {
        Node *del_node = front;
        front = front->next;
        delete del_node;
    }
    cout<<endl;
}

void DEQueue_Class ::Enqueue_from_rear()
{
    int element;
    cout << "Enter the element which you want to insert from the rear: ";
    cin >> element;
    Node *rear_Insertion = new Node;
    rear_Insertion->data = element;
    rear_Insertion->next = NULL;
    if (isEmpty())
    {
        front = rear_Insertion;
    }
    else
    {
        rear->next = rear_Insertion;
        rear = rear_Insertion;
    }
}

void DEQueue_Class ::Enqueue_from_front()
{
    int element;
    cout << "Enter the Data which you want to insert from the front: ";
    cin >> element;
    Node *ins_front = new Node;
    ins_front->data = element;
    if (isEmpty())
    {
        ins_front = front;
    }
    else
    {
        ins_front->next = front;
        front = ins_front;
    }
}

void DEQueue_Class::display()
{
    reset_Pos();
    if (isEmpty())
    {
        cout << "Queue is Empty!!!!!!!!!!";
    }
    else
    {
        cout << "Element in the Queue is: ";
        while (ptr != NULL)
        {
            cout << ptr->data;
            if (ptr == rear)
            {
                cout << " ";
            }
            else
            {
                cout << ",";
            }
            ptr = ptr->next;
        }
    }
    cout << endl;
}

void DEQueue_Class::Insert_in_the_queue()
{
    int element;
    char ch = 'y';
    int count = 0;
    while (ch == 'y' || ch == 'Y')
    {
        Node *currentNode = new Node;
        cout << "Enter the data in the node " << count + 1 << " : ";
        cin >> element;
        currentNode->data = element;
        currentNode->next = NULL;
        if (isEmpty())
        {
            front = rear = currentNode;
        }
        else
        {
            rear->next = currentNode;
            rear = currentNode;
        }
        count++;
        cout << "Do you want to enter More? (y/n) : ";
        cin >> ch;
    }
}

void DEQueue_Class::reset_Pos()
{
    ptr = front;
}

bool DEQueue_Class::isEmpty()
{
    if (front == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int choice;
    DEQueue_Class operations;

    do
    {
        cout << "1. Insertion in the Queue" << endl;
        cout << "2. Display the Queue" << endl;
        cout << "3. Perform the Enqueue Operation from the front" << endl;
        cout << "4. Perform the Enqueue Operation from the rear" << endl;
        cout << "5. Perform the Dequeue Operation from the front" << endl;
        cout << "6. Perform the Dequeue Operation from the rear" << endl;
        cout << "7. Exit";
        cout << endl;
        cout << "Enter your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            operations.Insert_in_the_queue();
            break;
        }
        case 2:
        {
            operations.display();
            break;
        }
        case 3:
        {
            operations.Enqueue_from_front();
            break;
        }
        case 4:
        {
            operations.Enqueue_from_rear();
            break;
        }
        case 5:
        {
            operations.Dequeue_from_front();
            break;
        }
        case 6:
        {
            operations.Dequeue_from_rear();
            break;
        }
        case 7:
        {

            break;
        }

        default:
        {
            cout << "Wrong Choice !!!!!!!!!!" << endl;
            break;
        }
        }

    } while (choice != 7);

    return 0;
}