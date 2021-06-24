#include<iostream>

using namespace std;
#define max 10

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
};
int main()
{
    int nums[5],t[5];
    int i,j,k,c=0,rev=0,rev_2=0,remainder,n;
    Stack s;

    for(i=0;i<5;i++)
        cin>>nums[i];
    for(i=0;i<5;i++)
    {
        c=0,rev=0,rev_2=0;

        while (nums[i] != 0)
        {
            remainder = nums[i] % 10;
            rev = rev * 10 + remainder;
            nums[i] /= 10;
            c++;
        }

        while(rev != 0)
        {
            s.push(rev%10);
            rev /= 10;
        }

        for(j=c;j>0;j--)
        {
            k=s.pop();
            rev_2 = rev_2*10 + k;
        }

        nums[i] = rev_2;
    }

    for(i=0;i<5;i++)
        cout<<nums[i]<<" ";
    return 0;
}
