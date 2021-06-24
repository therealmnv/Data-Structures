#include<iostream>
using namespace std;

class List
{
    int coe;
    int exp;
    List* link;
public:
    List* create(List*,int,int);
    void traverse(List*);
    List* add(List*,List*);
    List* mul(List*,List*);
    List* simp(List*);
};

List* first1=NULL;

List* first2=NULL;

List* first3=NULL;

List* first4=NULL;

List* List::create(List* first,int c,int e)
{
    List* temp=new List;

    temp->coe=c;
    temp->exp=e;
    temp->link=NULL;

    if(first==NULL)
    {
        first=temp;
    }
    else
    {
        List* curr;
        for(curr=first;curr->link!=NULL;curr=curr->link);
        curr->link=temp;
    }
    return first;
}

void List::traverse(List *p)
{
    List *curr;
    cout<<"\nDisplaying...\n";
    for(curr=p;curr!=NULL;curr=curr->link)
    {
        cout<<curr->coe<<"x^"<<curr->exp;
        if(curr->link!=NULL && curr->coe>=0)
        {
            cout<<"+";
        }
    }
    cout<<endl;


}

List* List::add(List* first,List* second)
{
    List* res=NULL;

    while(first!=NULL && second!=NULL)
    {
        if(first->exp>second->exp)
        {
            res=create(res,first->coe,first->exp);
            first=first->link;
        }
        else if(first->exp==second->exp)
        {
            res=create(res,first->coe+second->coe,first->exp);
            first=first->link;
            second=second->link;
        }
        else
        {
            res=create(res,second->coe,second->exp);
            second=second->link;
        }
    }
    while(first!=NULL)
    {
        res=create(res,first->coe,first->exp);
        first=first->link;
    }
    while(second!=NULL)
    {
        res=create(res,second->coe,second->exp);
        second=second->link;
    }
    return res;
}

List* List::mul(List* first,List* second)
{
    List* res=NULL;

    for(List* i=first;i!=NULL;i=i->link)
    {
        for(List* j=second;j!=NULL;j=j->link)
        {
            res=create(res,i->coe * j->coe,i->exp + j->exp);
        }
    }
    res=simp(res);
    return res;
}

List* List::simp(List* s)
{
    List* res=NULL;
    int a[20],b[20],largestExp=s->exp;

    for(List* i=s;i!=NULL;i=i->link)
    {
        if(i->exp>largestExp)
            largestExp=i->exp;
    }

    for(int j=largestExp;j>=0;j--)
    {
        a[j]=0;
        b[j]=0;
    }

    for(List* i=s;i!=NULL;i=i->link)
    {
        a[i->exp]+=i->coe;
        b[i->exp]=1;
    }

    for(int k=largestExp;k>=0;k--)
    {
        if(b[k]==1)
            res=create(res,a[k],k);
    }

    return res;
}

int main()
{
    int n,i,e,c; List a;
    cout<<"How many terms in 1st polynomial\n"; cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"\nEnter coe: "; cin>>c;
        cout<<"Enter exp: "; cin>>e;
        first1=a.create(first1,c,e);
    }
    a.traverse(first1);
    cout<<"How many terms in 2nd polynomial\n"; cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"\nEnter coe: "; cin>>c;
        cout<<"Enter exp: "; cin>>e;
        first2=a.create(first2,c,e);
    }
    a.traverse(first2);
    first3=a.add(first1,first2);
    first4=a.mul(first1,first2);
    cout<<"Result of addition: "; a.traverse(first3); cout<<endl;
    cout<<"Result of multiplication: "; a.traverse(first4); cout<<endl;
}
