#include <iostream>
using namespace std;

class dll
{
    int data;
    dll* prev;
    dll* next;
public:
    void create();
    void insBefore();
    void insAfter();
    void delSpecific();
    void traverse();
    void rev();
};

dll* first=NULL;

void dll::create()
{
    int x;
    cout<<"Enter value: ";
    cin>>x;

    dll* temp=new dll;
    temp->data=x;
    temp->next=NULL;
    temp->prev=NULL;

    if(first==NULL)
        first=temp;
    else
    {
        dll* curr;
        for(curr=first;curr->next!=NULL;curr=curr->next);
        curr->next=temp;
        temp->prev=curr;
    }
}

void dll::insBefore()
{
    int x,n,flag=0;
    dll *temp,*curr;
    temp=new dll;
    cout<<"Enter number before which node is to be inserted: ";
    cin>>x;

    if(first==NULL)
        cout<<"List is empty";
    else if(first->data==x)
    {
        cout<<"Enter number to be inserted: ";
        cin>>n;

        temp->data=n;
        temp->next=first;
        temp->prev=NULL;
        first=temp;
        flag=1;
    }
    else
    {
        for(curr=first->next;curr!=NULL;curr=curr->next)
        {
            if(curr->data==x)
            {
                cout<<"Enter number to be inserted: ";
                cin>>n;
                temp->data=n;
                temp->next=curr;
                temp->prev=curr->prev;
                curr->prev->next=temp;
                curr->prev=temp;
                flag=1;
                break;
            }
        }
    }
    if(flag==0)
        cout<<"Element not found";
}

void dll::insAfter()
{
    int x,n,flag=0;
    dll *temp,*curr;
    temp=new dll;
    cout<<"Enter number after which node is to be inserted: ";
    cin>>x;

    if(first==NULL)
        cout<<"List is empty";
    else if(first->data==x)
    {
        cout<<"Enter number to be inserted: ";
        cin>>n;

        temp->data=n;
        temp->next=first->next;
        temp->prev=first;

        if(first->next!=NULL)
            first->next->prev=temp;

        flag=1;
    }
    else
    {
        for(curr=first;curr!=NULL;curr=curr->next)
        {
            if(curr->data==x && curr->next!=NULL)
            {
                cout<<"Enter number to be inserted: ";
                cin>>n;

                temp->data=n;
                temp->next=curr->next;
                temp->prev=curr;
                curr->next->prev=temp;
                curr->next=temp;
                flag=1;
                break;
            }
            else if(curr->data==x && curr->next==NULL)
            {
                cout<<"Enter number to be inserted: ";
                cin>>n;

                temp->data=n;
                temp->next=NULL;
                temp->prev=curr;
                curr->next=temp;
                flag=1;
                break;
            }
        }
    }
    if(flag==0)
        cout<<"Element not found";
}

void dll::delSpecific()
{
    int x,flag;
    dll* curr;

    cout<<"Enter element to be deleted";
    cin>>x;

    if(first==NULL)
        cout<<"List is Empty";
    else if(first->data==x)
    {
        dll* temp=first;
        first=first->next;
        first->prev=NULL;
        delete(temp);
        flag=1;
    }
    else
    {
        for(curr=first;curr!=NULL;curr=curr->next)
        {
            if(curr->data==x && curr->next!=NULL)
            {
                curr;
                curr->prev->next=curr->next;
                curr->next->prev=curr->prev;
                delete(curr);
                flag=1;
                break;
            }
            else if(curr->data==x && curr->next==NULL)
            {
                curr->prev->next=NULL;
                delete(curr);
                flag=1;
                break;
            }
        }
    }
    if(flag==0)
        cout<<"Element not found";
}

void dll::rev()
{
    dll *prev1,*curr;
    prev1=curr=NULL;

    while(first!=NULL)
    {
        prev1=curr;
        curr=first;
        first=first->next;
        curr->next=prev1;
        if(prev1) //if(prev1 != NULL)
            prev1->prev=curr;
    }
    curr->prev=NULL;
    first=curr;
}

void dll::traverse()
{
    dll* p;
    cout<<"\nDisplaying...\n";
    for(p=first;p!=NULL;p=p->next)
        cout<<p->data<<"\t";
}

main()
{ dll l; int ch;
do
{
cout<<"\n1 create\n2 insert before\n3 insert after\n4 delete specific \n 5traverse\n6.reverse\n0.exit";
cout<<"\nenter your choice:"; cin>>ch;
switch(ch) { case 1:l.create();break;
case 2:l.insBefore();break;
case 3:l.insAfter();break;
case 4:l.delSpecific();break;
case 5:l.traverse();break;
case 6:l.rev();break;
case 0:break;
default:cout<<"\ninvalid input";break;
} }while(ch!=0);
}
