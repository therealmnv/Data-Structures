#include <iostream>
using namespace std;

class cdll
{
    int data;
    cdll* prev;
    cdll* next;
public:
    void init();
    void ins();
    void del();
    void disp();
    void rev();
};

cdll* headnode=NULL;

void cdll::init()
{
    headnode=new cdll;
    headnode->next=headnode;
    headnode->prev=headnode;
}

void cdll::ins()
{
    cdll *temp,*curr;
    temp=new cdll;

    int x;
    cout<<"Enter number: ";
    cin>>x;

    temp->data=x;
    temp->next=headnode;

    if(headnode->next==headnode)
    {
        temp->prev=headnode;
        headnode->prev=temp;
        headnode->next=temp;
    }

    else
    {
        curr=headnode->next;
        while(curr->next!=headnode)
        {
            curr=curr->next;
        }
        curr->next=temp;
        temp->prev=curr;
        headnode->prev=temp;
    }
}

void cdll::del()
{
    cdll* temp;
    cdll *curr=headnode->next;
    cdll* prev;
    if(headnode->next==headnode)
    {
        cout<<"Circular List is Empty";
    }
    else if(curr->next==headnode)
    {
        temp=headnode->next;
        headnode->next=headnode;
        headnode->prev=headnode;
        delete(temp);
    }
    else
    {
        while(curr->next!=headnode)
        {
            prev=curr;
            curr=curr->next;
        }
        prev->next=headnode;
        headnode->prev=prev;
        delete(curr);
    }
}

void cdll::disp()
{
    if(headnode->next==headnode)
    {
        cout<<"Circular List is Empty";
    }
    else
    {
        cdll* curr=headnode->next;
        while(curr!=headnode)
        {
            cout<<curr->data<<" ";
            curr=curr->next;
        }
    }
}

void cdll::rev()
{
    if(headnode->next==headnode)
        cout<<"Circular List is Empty";
    else
    {
        cdll* curr=headnode->prev;
        while(curr!=headnode)
        {
            cout<<curr->data<<"\t";
            curr=curr->prev;
        }
    }
}

main()
{
cdll a; int ch,n; a.init();
do
{ cout<<"\n1.insert\n2.delete\n3.disp\t\n4.reverse\t5.Exit\nEnter your choice: ";
cin>>ch;
switch (ch)
{
case 1: a.ins(); break;
case 2: a.del(); break;
case 3: a.disp(); break;
case 4: a.rev(); break;
default: "Invalid";
}
}while(ch!=5);
}
