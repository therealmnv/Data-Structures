#include<iostream>
using namespace std;

class List
{
    private:
        int data;
        List* link;
    public:
        void ins_front();
        void ins_end();
        void del_front();
        void del_end();
        void del_specific();
        void traverse();
        void counter();
        void insert_in_sorted();
        void sorter();
        void rev();
        void ins_n(int);
};

List* first=NULL;

void List::traverse()
{
    List* p;
    cout<<"\nDisplaying...\n";
    for(p=first;p!=NULL;p=p->link)
        cout<<p->data<<endl;
}

void List::ins_front()
{
    List* temp;
    temp = new List;

    cout<<"\nEnter element to be added at the start: ";
    cin>>temp->data;

    if(first==NULL)
    {
        temp->link=NULL;
        first=temp;
    }
    else
    {
        temp->link=first;
        first=temp;
    }

    traverse();
}

void List::ins_end()
{
    List *temp;
    temp = new List;

    cout<<"\nEnter element to be added at the end: ";
    cin>>temp->data;

    if(first==NULL)
    {
        temp->link=NULL;
        first=temp;
    }
    else
    {   List* curr;
        for(curr=first;curr->link!=NULL;curr=curr->link);
        curr->link=temp;
    }

    traverse();
}
//To delete first set a new pointer to  point at the element to be deleted and then delete
void List::del_front()
{
    if(first==NULL)
        cout<<"\nList is empty\n";
    else
    {
        cout<<"\nDeleting from front...\n";
        List* temp=first; //temp and first point to the same memory location
        first=first->link;
        delete temp;
    }

    traverse();
}
void List::del_end()
{
    //case 1
    if(first==NULL)
        cout<<"\nList is empty\n";
    //case 2
    else if(first->link==NULL)
    {
        cout<<"\nDeleting from end...\n";
        List* temp=first;
        first=NULL;
        delete temp;
    }
    else
    {
        cout<<"Deleting from end...\n";
        List* prev;
        List* curr;
        for(curr=first;curr->link!=NULL;curr=curr->link)
            prev=curr;
        prev->link=NULL;
        delete curr;
    }

    traverse();
}

void List::del_specific()
{
        int x;
        cout<<"\nEnter the element to be deleted: ";
        cin>>x;

        if(first==NULL)
            cout<<"\nList is empty\n";
        else if(first->data==x)
        {
            List* temp=first;
            first=first->link;
            delete temp;
        }
        else
        {
            List* prev;
            List* curr;
            int flag=0;
            for(curr=first;curr!=NULL;curr=curr->link)
            {
                if(curr->data==x)
                {
                    prev->link=curr->link;
                    delete curr;
                    flag=1;
                    break;
                }
                prev=curr;
            }
            if(flag==0)
                cout<<"\nNumber not found\n";
        }
}
/*void List::insert_in_sorted()
{
    List* temp;
    temp = new List;
    cout<<"\nEnter element to be added: ";
    cin>>temp->data;

    if(first==NULL)
    {
        first=temp;
        return;
    }
    List* prev=NULL;
    List* curr=first;
    while((curr!=NULL) && (temp->data>curr->data))
    {
        prev=curr;
        curr=curr->link;
    }
    if(curr!=NULL)
    {
        if(prev!=NULL)
        {
            prev->link=temp;
            temp->link=curr;
        }
        else
        {
            temp->link=first;
            first=temp;
        }
    }
    else
        prev->link=temp;
}*/

void List::sorter()
{
    List* i;
    List* j;
    for(i=first;i->link!=NULL;i=i->link)
    {
        for(j=i->link;j!=NULL;j=j->link)
        {
            if(i->data>j->data)
            {
                int d=i->data;
                i->data=j->data;
                j->data=d;
            }
        }
    }
    cout<<"\nThe sorted list is...\n";
    traverse();
}

void List::ins_n(int n)
{
    List* temp= new List;
    temp->data=n;
    temp->link=NULL;

    if(first==NULL)
    {
        first=temp;
        return;
    }

    List* prev=NULL;
    List* curr=first;

    while(curr!=NULL && n>curr->data)
    {
        prev=curr;
        curr=curr->link;
    }
    if(curr==NULL)
    {
        prev->link=temp;
    }
    else
    {
        if(prev!=NULL)
        {
            temp->link=curr;
            prev->link=temp;
        }
        else
        {
            temp->link=first;
            first=temp;
        }
    }
    traverse();
}

void List::rev()
{
    List *curr, *prev;
    curr=prev=NULL;
    while(first!=NULL)
    {
        prev=curr;
        curr=first;
        first=first->link;
        curr->link=prev;
    }
    first=curr;
}

main()
{
    List l;
    int ch,n;
    do
    {
        cout<<"\n1 Insert end\t2 Insert front\t\t3 Delete front\n4 delete end\t5. delete specific\t6.traverse\t7.count\n0.exit";
        cout<<" 8. Insert nth node \n 9. sort 10. reverse \nenter your choice:";
        cin>>ch;

        switch(ch)
        {   case 1:l.ins_end();break;
            case 2:l.ins_front();break;
            case 3:l.del_front();break;
            case 4:l.del_end();break;
            case 5:l.del_specific();break;
            case 6:l.traverse();break;
            //case 7:cout<<"\nNo of nodes: "<<l.count()<<endl; break;
            case 8:cout<<"Enter number: "; cin>>n; l.ins_n(n); break;
            case 9:l.sorter(); break;
            case 10: l.rev();break;
            case 0:break;
            default:cout<<"\ninvalid input";break;
        }

    }while(ch!=0);
}
