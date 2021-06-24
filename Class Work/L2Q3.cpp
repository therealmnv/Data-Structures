#include<iostream>
#define max 5
using namespace std;

class Stack
{
private:
    int top;
public:
    int a[max];

    Stack()
    {
        top = -1;
    }

    void push(int x)
    {
        if(top==max-1)
            cout<<"Stack Overflow"<<endl;
        else
        {
            a[++top] = x;
            //cout<<x<<" pushed into stack"<<endl;
        }
    }

    int pop()
    {
        if(top<0)
        {
            cout<<"Stack Underflow"<<endl;
            return 0;
        }
        else
            return a[top--];
    }

    void display()
    {
        if(top>=0)
        {
            for(int i=top;i>=0;i--)
                cout<<a[i]<<"\t";
        }
        else
        {
            cout<<"Stack is empty"<<endl;
        }
    }
};

main()
{
    int n,b;
    Stack s;

    cout<<"Enter decimal number: ";
    cin>>n;

    cout<<"Enter base: ";
    cin>>b;

    do
    {
        s.push(n%b);
        n=n/b;
    }while(n>0);

    s.display();
}
