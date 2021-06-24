#include<iostream>
using namespace std;

class heap
{
    public:
    int key;
    void insert();
    void sort();
    void adjust(heap*,int);
    void disp();
    void delMax();
};

heap h[20];
int n=0;

void heap::insert()
{
    if(n==20)
        cout<<"\nHeap is Full\n";
    else
    {
        int x;

        cout<<"\nEnter element to be inserted: ";
        cin>>x;

        int i=++n;

        while(i!=1 && x>=h[i/2].key)
        {
            h[i].key=h[i/2].key;
            i=i/2;
        }

        h[i].key=x;
    }
    disp();
}

void heap::disp()
{
    cout<<"Heap is: ";
    for(int i=1;i<=n;i++)
        cout<<h[i].key<<" ";
}

void heap::delMax()
{
    if(n==0)
    {
        cout<<"Heap is empty!";
        return;
    }

    h[1].key=h[n].key;

    n=n-1;

    int i=1,temp;

    while((2*i<=n && (2*i)+1<=n) && (h[i].key<h[2*i].key || h[i].key<h[2*i+1].key))
    {
        if((h[2*i].key>=h[2*i+1].key))
        {
            temp=h[i].key;
            h[i].key=h[2*i].key;
            h[2*i].key=temp;
            i=i*2;
        }

        else
        {
            temp=h[i].key;
            h[i].key=h[2*i+1].key;
            h[2*i+1].key=temp;
            i=(i*2)+1;
        }
    }

    if(n==2 && h[i].key<h[2*i].key)
    {
        temp=h[i].key;
        h[i].key=h[2*i].key;
        h[2*i].key=temp;

        //i=i*2;
    }
}

void heapify(heap h[],int m)
{
    int i=1,temp;

    while((2*i<=m && 2*i+1<=m) && (h[i].key<=h[2*i].key || h[i].key<=h[2*i+1].key))
    {
        if(h[2*i].key>h[2*i+1].key)
        {
            temp=h[i].key;
            h[i].key=h[2*i].key;
            h[2*i].key=temp;
            i=i*2;
        }

        else
        {
            temp=h[i].key;
            h[i].key=h[2*i+1].key;
            h[2*i+1].key=temp;
            i=i*2+1;
        }
    }

    if(h[i].key>h[2*i].key && m==2)
    {
        temp=h[i].key;
        h[i].key=h[2*i].key;
        h[2*i].key=temp;
        i=i*2;
    }
}

void heap::sort()
{
    int i=n;

    while(i>1)
    {
        int temp=h[1].key;
        h[1].key=h[i].key;
        h[i].key=temp;
        i--;
        heapify(h,i);
    }
}

int main()
{
    heap m; int ch;

    do
    {
        cout<<"\n1. Insert\n2. Sort\n3. Display\n4. delete\n0. Exit";
        cout<<"\n Enter Your Choice";
        cin>>ch;
        switch(ch)
        {
            case 1: m.insert();
                    break;
            case 2: m.sort();
                    break;
            case 3: m.disp();
                    break;
            case 4: m.delMax();
                    break;
            case 0: break;
            default: cout<<"\nInvalid choice";break;
        }
    }while(ch!=0);
    return 1;
}
