#include<iostream>
using namespace std;

class clist
{
    private:
        int data;
        clist* next;
    public:
        void ins(int);
        void del();
        void disp();
        void init();
};

clist* headnode;

void clist::init()
{
    headnode=new clist;
    headnode->next=headnode;
}

void clist::ins(int x)
{
    clist *temp,*curr;
    temp=new clist;
    temp->data=x;
    temp->next=headnode;

    if(headnode->next==headnode)
    {
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
    }
}

void clist::del()
{
    clist* temp;
    clist *curr=headnode->next;
    clist* prev;
    if(headnode->next==headnode)
    {
        cout<<"Circular List is Empty";
    }
    else if(curr->next==headnode)
    {
        temp=headnode->next;
        headnode->next=headnode;
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
        delete(curr);
    }
}

void clist::disp()
{
    if(headnode->next == headnode)
    {
        cout<<"Circular List is Empty";
    }
    else
    {
        clist* curr=headnode->next;
        while(curr!=headnode)
        {
            cout<<curr->data<<" ";
            curr=curr->next;
        }
    }
}

main()
{
clist a; int ch,n; a.init();
do
{ cout<<"\n1.insert\n2.delete\n3.disp\t\n4.exit\nEnter your choice: ";
cin>>ch;
switch (ch)
{
case 1: cout<<"Val: "; cin>>n;a.ins(n); break;
case 2: a.del(); break;
case 3: a.disp(); break;
default: "Invalid";
}
}while(ch!=4);
}
