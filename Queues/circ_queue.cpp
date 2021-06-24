#include<iostream>
using namespace std;
#define maxxx 3

class cQueue
{
private:

    int a[maxxx],f,r,counter;

public:

    cQueue()
    {
        int f=-1,r=-1,counter=0;
    }

    int isFull()
    {
        if(counter==maxxx)
            return 1;
        else
            return 0;
    }

    int isEmpty()
    {
        if(counter==0)
            return 1;
        else
            return 0;
    }

    void add(int x)
    {
        if(isFull())
            cout<<"Queue full"<<endl;
        else
        {
            r=(r+1)%maxxx;
            a[r]=x;
            cout<<"Element added: "<<x<<endl;
            counter++;
        }
    }

    void del()
    {
        if(isEmpty())
            cout<<"Queue empty"<<endl;
        else
        {
            cout<<"Element deleted "<<a[f]<<endl;
            f=(f+1)%maxxx;
            counter--;
        }
    }

    void disp()
    {
        if(isEmpty())
            cout<<"Queue empty";
        else
        {
            for(int i=(f+1)%maxxx;i<(r+1)%maxxx;i++)
                cout<<a[i]<<endl;
        }
    }

};

main()
{
    cQueue q;
    int i;

    do
    {
        cout<<"1 Add\n2 Delete\n3 Display\n4 Exit"<<endl;
        cin>>i;

        switch(i)
        {
            case 1:
                {
                    cout<<"Enter element to be added to cQ"<<endl;
                    cin>>i;
                    q.add(i);
                    cout<<endl;
                    break;
                }
            case 2:
                {
                    q.del();
                    cout<<endl;
                    break;
                }
            case 3:
                {
                    q.disp();
                    cout<<endl;
                    break;
                }
        }
    }while(i!=4);
}
