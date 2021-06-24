#include<iostream>
using namespace std;

class List
{
    int data;
    List* link;
public:
    List* create(List*,int);
    void traverse(List*);
    List* mergee(List*,List*);
    List* concat(List*,List*);
};

List* first1=NULL;

List* first2=NULL;

List* first3=NULL;

List* List::create(List* first, int x)
{
    List *temp = new List;
    temp->data=x;
    temp->link=NULL;

    if(first==NULL)
    {
        first=temp;
    }
    else
    {
        List *curr;
        for(curr=first;curr->link!=NULL;curr=curr->link);
        curr->link=temp;
    }
    traverse(first);
    return first;
}

List* List::mergee(List *first, List *second)
{
    List* res=NULL;
    while(first!=NULL&&second!=NULL)
    {
        if(first->data<=second->data)
        {
            res=create(res,first->data);
            first=first->link;
        }
        else
        {
            res=create(res,second->data);
            second=second->link;
        }
    }
    while(first!=NULL)
    {
        res=create(res,first->data);
        first=first->link;
    }
    while(second!=NULL)
    {
        res=create(res,second->data);
        second=second->link;
    }
    return res;
}

List* List::concat(List *first, List *second)
{
    if(first==NULL)
    {
        first=second;
    }
    else if(second==NULL)
    {

    }
    else
    {
        List *curr;
        for(curr=first;curr->link!=NULL;curr=curr->link);
        curr->link=second;
    }
    traverse(first);
    return first;
}

void List::traverse(List *p)
{
    cout<<"\nDisplaying...\n";
    for(List *curr=p;curr!=NULL;curr=curr->link)
        cout<<curr->data<<"\t";
    cout<<endl;
}

main()
{
    List d;
    int ch,l,l2,v;
    do
    {
        cout<<"\nEnter the following\n1:Create\t2:Merge\t3:Concatenate\n4:Traverse\t0:Exit\n";
        cout<<"\n---> ";
        cin>>ch;
        cout<<endl;

        switch(ch)
        {
            case 1:
                {
                    cout<<"Which list? ";
                    cin>>l;
                    cout<<endl;
                    cout<<"Enter value: ";
                    cin>>v;
                    cout<<endl;
                    switch(l)
                    {
                    case 1:
                        first1=d.create(first1,v);
                        break;
                    case 2:
                        first2=d.create(first2,v);
                        break;
                    default:
                        cout<<"Enter values as 1 or 2 only"<<endl;
                    }
                    break;
                }

            case 2:
                {
                    cout<<"Merging..."<<endl;
                    first3=d.mergee(first1, first2);
                    break;
                }
            case 3:
                {
                    cout<<"Concatenating..."<<endl;
                    first3=d.concat(first1, first2);
                    break;
                }
            case 4:
                {
                    cout<<"Which list? "<<endl;
                    cin>>l;
                    switch(l)
                    {
                    case 1:
                        d.traverse(first1);
                        break;
                    case 2:
                        d.traverse(first2);
                        break;
                    default:
                        cout<<"Enter values as 1 or 2 only"<<endl;
                    }
                    break;
                }
            case 0:
                cout<<"Exiting..."<<endl;
                break;
            default:
                cout<<"Invalid Input! Try Again..."<<endl;
        }

    }while(ch!=0);
}
