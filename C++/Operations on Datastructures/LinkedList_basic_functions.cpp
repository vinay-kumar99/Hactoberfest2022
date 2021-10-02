#include<bits/stdc++.h>
using namespace std;
struct llist
{
    int val;
    llist *next;
};
llist *head = nullptr;
llist* newnode(int x)          //create new node and return it's address
{
    llist *temp=new llist();
    temp->val=x;
    temp->next = nullptr;
    return temp;
}
void addbegin(int x)            //add a node at the begining
{
    llist *link = newnode(x);
    link->next = head;
    head = link;
}
void addend(int x)              //add a node at the end
{
    llist *t=head;
    llist *newn=newnode(x);
    if(t!=nullptr)
    {
        while(t->next!=nullptr)
        {
        t=t->next;
        }
    t->next=newn;
    newn->next=nullptr;
    }
    else
    {
        head=newn;
        newn->next=nullptr;
    }

}
int len()                   //length of the linked list
{
    llist* temp=head; int c=0;
    while(temp->next!=nullptr)
        {
            c++;
            temp = temp->next;
        }
    return c+1;
}
void printllist()               //print the linked list
{
    llist* temp=head;
    while(temp!=nullptr)
        {
            cout<<temp->val<<" ";
            temp=temp->next;
        }
    cout<<endl;
}
void searchllist(int n)         //search in the linked list
{
    llist* temp = head; int c=1;
    while(temp!=nullptr)
    {
        if(temp->val==n)
        {
            cout<<"found in "<<c<<"th node"<<endl;
            return;
        }
        c++;
        temp=temp->next;
    }
    cout<<"Not found :("<<endl;
}
void deleteall()            //delete complete linked list
{
    llist* temp = head;
    while(head!=nullptr)
    {
        temp=head;
        head = temp->next;
        free(temp);
    }
    return;
}
void deletellist(int n)       //delete node with value n
{
    llist* temp=head;
    llist* extra;
    for(int i=1;i<n-1;i++)
    {
        temp=temp->next;
    }
    extra=temp->next;
    temp->next=extra->next;
    free(extra);
}
int main()
{
    cout<<"linked list"<<endl;
    cout<<"input 5 test values "<<endl; int t=5; int ip;
    while(t--)
    {
        cin>>ip;
        addend(ip);
    }
    cout<<"llist values : ";
    printllist();
    return 0;
}