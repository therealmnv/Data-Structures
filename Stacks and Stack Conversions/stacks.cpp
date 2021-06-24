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
            cout<<x<<" pushed into stack"<<endl;
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

    int peek()
    {
        if(top<0)
        {
            cout<<"Empty stack"<<endl;
            return 0;
        }

        else
            return a[top];
    }

    bool isEmpty()
    {
        if(top<0)
            return TRUE;
        else
            return FALSE;
    }

    bool isFull()
    {
        if(top==max-1)
            return TRUE;
        else
            return FALSE;

    }

    void display()
    {
        if(top>=0)
        {
            for(int i=top;i>=0;i--)
                cout<<a[i]<<endl;
        }
        else
        {
            cout<<"Stack is empty"<<endl;
        }
    }
};

main()
{
    Stack s;
    s.display();
    cout<<s.isEmpty()<<endl;
    s.push(10);
    s.push(20);
    cout<<"Popped element: "<<s.pop()<<endl;
    cout<<"Topmost element is: "<<s.peek()<<endl;
    s.push(20);
    s.push(30);
    s.push(40);
    s.display();
    cout<<s.isFull();
}
