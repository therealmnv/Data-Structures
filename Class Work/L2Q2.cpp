#include<iostream>
#include<string.h>
#define max 10
using namespace std;

class Stack
{
private:
    int top;
public:
    char a[max];

    Stack()
    {
        top = -1;
    }

    void push(char x)
    {
        if(top==max-1)
            cout<<"Stack Overflow"<<endl;
        else
        {
            a[++top] = x;
            cout<<x<<" pushed into stack"<<endl;
        }
    }

    char pop()
    {
        if(top<0)
        {
            cout<<"Stack Underflow"<<endl;
            return '*';
        }
        else
            return a[top--];
    }
};

main()
{
    Stack s1,s2;
    char ch[100];
    int flag=0;
    cout<<"Enter string to check for palindrome: ";
    cin>>ch;
    int n=strlen(ch);

    for(int i=0;i<n;i++)
    {
        s1.push(ch[i]);
    }

    for(int i=0;i<n;i++)
    {
        if(s1.pop() != ch[i])
        {
            cout<<"Not a palindrome";
            flag =1;
            break;
        }
    }

    if(flag==0)
        cout<<"Palindrome";
}
