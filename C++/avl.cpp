#include<iostream>
using namespace std;
class Node
{
private:
    int data;
    Node *left;
    Node *right;
    int height;
public:
    Node()
    {}
    Node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
        height=0;
    }
    void setdata(int d)
    {
        data=d;
    }
    void setleft(Node *l)
    {
        left=l;
    }
    void setright(Node *r)
    {
        right=r;
    }
    int setheight(int h)
    {
        height=h;
    }
    int getdata()
    {
        return(data);
    }
    Node* getleft()
    {
        return(left);
    }
    Node *getright()
    {
        return(right);
    }
    int getheight()
    {
        return(height);
    }
};
class Avl
{
public:
    Node *root=NULL;
    int max(int a,int b)
    {
        return a>b?a:b;
    }
    int Height(Node *node)
    {
        return node==NULL?-1:node->getheight();
    }
    int Balance_Factor(Node *node)
    {
        return Height(node->getleft())-Height(node->getright());
    }

    Node* right_rotate(Node *node)
    {
        std::cout << "Right Rotating Node:" << node->getdata()<<'\n';
        Node *n2=node->getleft();
        node->setleft(n2->getright());
        n2->setright(node);
        n2->setheight(max(Height(n2->getleft()),Height(n2->getright()))+1);
        node->setheight(max(Height(node->getleft()),Height(node->getright()))+1);
        std::cout << "Returing Parent:" << n2->getdata()<<'\n';
        return n2;
    }
    Node *left_rotate(Node *node)
    {
        std::cout << "Left Rotating Node:" << node->getdata()<<'\n';

        Node *n2=node->getright();
        node->setright(n2->getleft());
        n2->setleft(node);
        n2->setheight(max(Height(n2->getleft()),Height(n2->getright()))+1);
        node->setheight(max(Height(node->getleft()),Height(node->getright()))+1);
        std::cout << "Returing Parent:" << n2->getdata()<<'\n';
        return n2;
    }
    Node* doubleLeftRotate(Node* temp)
    {
        temp->setright(right_rotate(temp->getright()));
        return left_rotate(temp);
    }

    Node* doubleRightRotate(Node* temp)
    {
        temp->setleft(left_rotate(temp->getleft()));
        return right_rotate(temp);
    }
    void Add(int value)
    {
        root=Add(root,value);
    }
    Node *Add(Node *start,int value)
    {
        int bf;
        if(start==NULL)
        {
            start=new Node(value);
        }
        else if(value<start->getdata())
        {
            start->setleft(Add(start->getleft(),value));
            bf=Balance_Factor(start);
            if(bf==2 || bf==-2)
            {
                //left left violation
                if(start->getleft()->getdata()>value)
                {

                    start=right_rotate(start);
                }
                else
                {
                    start->setleft(left_rotate(start->getleft()));
                    start=right_rotate(start);
                }
            }
            else
                std::cout << "Avl is still Balanced:" << '\n';
        }
        else if(value>start->getdata())
        {
            start->setright(Add(start->getright(),value));
            bf=Balance_Factor(start);
            if(bf==2 || bf==-2)
            {
                //right right violation
                if(start->getright()->getdata()<value)
                {
                    start=left_rotate(start);
                }
                else
                {
                    start->setright(right_rotate(start->getright()));
                    start=left_rotate(start);
                }
            }
            else
                std::cout << "Avl is still Balanced:" << '\n';
        }
        start->setheight(max(Height(start->getleft()),Height(start->getright()))+1);

        return(start);
    }

    void search(int value)
    {
        Node *temp=root;

        if(temp==NULL)
            std::cout << "Root is Null:" << '\n';
        else
            recursion(temp,value);
    }
    void recursion(Node *temp,int value)
    {
        if(temp==NULL)
        {
            cout << "No data found:" << '\n';
            return;
        }
        if(value==temp->getdata())
        {
            std::cout << "Data has been found:" << value<<'\n';
            return;
        }
        value<temp->getdata()?recursion(temp->getleft(),value):recursion(temp->getright(),value);

    }
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
    Node* Min(Node *node)
    {
        if(node==NULL)
            return NULL;
        return   node->getleft() == NULL?node:Min(node->getleft());
    }
    Node* Max(Node *node)
    {
        if(node==NULL)
            return NULL;
        return   node->getright() == NULL?node:Min(node->getright());

    }
    void remove_value(int d)        ///REMOVE FOR AVL
    {
        root=remove_r(d,root);
    }
    //END
    Node* remove_r(int x, Node* t)
    {
        Node* temp;
        if(t == NULL)
            return NULL;
        else if(x < t->getdata())
            t->setleft(remove_r(x, t->getleft()));
        else if(x > t->getdata())
            t->setright(remove_r(x, t->getright()));

        //2 child
        else if(t->getleft() && t->getright())
        {
            temp = Min(t->getright());
            t->setdata(temp->getdata());
            t->setright(remove_r(t->getdata(), t->getright()));

        }
        else//with one child
        {
            if(t->getleft() == NULL)
                t = t->getright();
            else if(t->getright() == NULL)
                t = t->getleft();
        }
        if(t == NULL)
            return t;

        t->setheight(max(Height(t->getleft()), Height(t->getright()))+1);

        // Now check for unbalanced, if
        // If left node is deleted, right case

        if(Height(t->getleft()) - Height(t->getright()) == -2)
       {
           // right right case
           if(Height(t->getright()->getright()) - Height(t->getright()->getleft()) == 1)
               return left_rotate(t);
           // right left case
           else
               return doubleLeftRotate(t);
       }
       // If right node is deleted, left case
       else if(Height(t->getright()) - Height(t->getleft()) == 2)
       {
           // left left case
           if(Height(t->getleft()->getleft()) - Height(t->getleft()->getright()) == 1){
               return right_rotate(t);
           }
           // left right case
           else
               return doubleRightRotate(t);
       }
        return t;
    }

//in order is between both if
    void Display(Node *start)
    {
        if(start==NULL)
        {
            std::cout << "NO value to Display" << '\n';
            return;
        }

        if(start->getleft()!=NULL)
        {
            Display(start->getleft());
        }
        cout<<start->getdata()<<endl;
        if(start->getright()!=NULL)
        {
            Display(start->getright());
        }
    }
};
int main()
{
    int condition,data;
    Avl avl;
    do
    {
        std::cout << "Press 1 to ADD value in AVL:" << '\n';
        std::cout << "Press 2 to Remove value in AVL:" << '\n';
        std::cout << "Press 3 to Display values in AVL:" << '\n';
        std::cout << "Press 4 to search value in AVL:" << '\n';
        std::cin >> condition;
        switch (condition)
        {
        case 1:
            std::cout << "Give the value you want to add:" << '\n';
            std::cin >> data;
            avl.Add(data);
            std::cout << "************************" << '\n';
            avl.Display(avl.root);
            std::cout << "************************" << '\n';
            break;
        case 2:
            std::cout << "Give the value you want to remove:" << '\n';
            std::cin >> data;
            avl.remove_value(data);
            std::cout << "Avl has been Balanced:" << '\n';
        case 3:
            std::cout << "************************" << '\n';
            avl.Display(avl.root);
            std::cout << "************************" << '\n';
            break;
        case 4:
            std::cout << "Give the value you want to search:" << '\n';
            std::cin >> data;
            avl.search(data);
            break;
        default:
        std::cout << "You have given a wrong input:" << '\n';
        break;
        }
        std::cout << "If you want to continue Press any number else Press ..0.." << '\n';
        std::cin >> condition;
    }
    while(condition!=0);
    return(0);
}
