#include<iostream>
using namespace std;
#define max 5
class twoStacks
{
private:
    int top1, top2;
    int a[max];
public:
    twoStacks()
    {
        top1=-1;
        top2=max;
    }

    void push1(int x)
    {
        if(top1<top2-1)
            {
                a[++top1]=x;
                cout<<"Pushed element in 1 is: "<<x<<endl;
            }
        else
            cout<<"Stack Overflow"<<endl;
    }

    void push2(int x)
    {
        if(top1<top2-1)
            {
                a[--top2]=x;
                cout<<"Pushed element in 2 is: "<<x<<endl;
            }
        else
            cout<<"Stack Overflow"<<endl;
    }

    void pop1()
    {
        if(top1<0)
        {
            cout<<"Stack underflow"<<endl;
        }
        else
            cout<<"Popped element is: "<<a[top1--]<<endl;
    }

    void pop2()
    {
        if(top2>max-1)
        {
            cout<<"Stack underflow"<<endl;
        }
        else
            cout<<"Popped element is: "<<a[top2++]<<endl;
    }
};

main()
{
    twoStacks ts;
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);
    ts.pop1();
    ts.push2(40);
    ts.pop2();
}
