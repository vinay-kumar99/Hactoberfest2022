#include<iostream>
using namespace std;
#include "Node.cpp"

// Hard Problem

class pair_ret{

public:

    Node *head;
    Node *tail;

};

pair_ret reverse(Node *head){

    if(head==NULL || head->next==NULL){
        pair_ret ans;
        ans.head=head;
        ans.tail=head;

        return ans;
    }

    pair_ret x = reverse(head->next);

    x.tail->next=head;
    x.tail = x.tail->next;
    head->next=NULL;

    return x;

}

Node * krever(Node * head, int k){

    if(head==NULL || head->next==NULL){
        return head;
    }

    Node * temp=head;
    int count=0;
    while(temp->next!=NULL && count<k-1){
        count++;
        temp=temp->next;
    }
    //Node * str = temp->next;

    Node * x = krever(temp->next,k);
    Node * temp1=head;
    int count1=0;
    while(temp1->next!=NULL && count1<k-1){
        count1++;
        temp1=temp1->next;
    }

    temp1->next=NULL;
    pair_ret small_ll = reverse(head);

    small_ll.tail->next=x;

    return small_ll.head;

}

Node * take_input(){

    int data;
    cin>>data;

    Node* head = NULL;
    Node*tail=NULL;

    while(data!=-1){
        Node *newnode = new Node(data);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=tail->next;
        }
        cin>>data;
    }

    return head;

}

void print(Node*head){

    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main(){

    Node * head = take_input();

    int n;
    cin>>n;

    head = krever(head,n);
    print(head);

}
