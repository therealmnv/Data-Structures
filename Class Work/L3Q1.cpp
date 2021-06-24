#include<iostream>
using namespace std;
#define maxx 10

class Queue
{
private:
    int r=-1,f=-1;
public:
    int a[maxx];

    int isFull()
    {
        if(r==maxx-1)
            return 1;
        else
            return 0;
    }

    int isEmpty()
    {
        if(r==f)
            return 1;
        else
            return 0;
    }

    void add(int x)
    {
        if(isFull())
        {
            cout<<"Queue full"<<endl;
        }
        else
        {
            a[++r]=x;
            cout<<"Added element: "<<x<<endl;
        }
    }

    void Delete()
    {
        if(isEmpty())
        {
            cout<<"Queue empty"<<endl;
        }
        else
        {
            cout<<"Deleted element: "<<a[++f]<<endl;
        }
    }

    void disp()
    {
        for(int i=f+1;i<=r;i++)
        {
            cout<<a[i]<<"\t";
        }
    }
};

main()
{
    Queue q;
    int i;

    do
    {
        cout<<"\n1 Add, 2 Delete, 3 Display, 4 Exit"<<endl;;
        cin>>i;

        switch(i)
        {
            case 1:
                {
                    cout<<"Enter element to be added to Q"<<endl;;
                    cin>>i;
                    q.add(i);
                    break;
                }
            case 2:
                {
                    q.Delete();
                    break;
                }
            case 3:
                {
                    q.disp();
                    break;
                }
            default:
                cout<<"Enter correct input"<<endl;
        }
    }while(i!=4);
}
