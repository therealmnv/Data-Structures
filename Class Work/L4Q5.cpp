#include<iostream>
#include<string.h>
#define maxx 30
using namespace std;

class Stack
{
private:
    int top;
public:
    char a[maxx];

    Stack()
    {
        top = -1;
    }

    void push(char x)
    {
        if(top==maxx-1)
            cout<<"Stack is full"<<endl;
        else
            a[++top]=x;
    }

    char pop()
    {
        if(top==-1)
        {
            cout<<"Stack is empty"<<endl;
        }
        else
            return a[top--];
    }

    void display()
    {
        for(int i=top;i>-1;i--)
            cout<<int(a[i]);
    }
};

main()
{
    char a[30];
    Stack s;

    cout<<"Enter character prefix: ";
    cin.get(a,30);

    for(int i=strlen(a)-1;i>-1;i--)
    {
        int token = a[i];
        if(token=='+' || token=='-' || token=='*' || token=='/' || token=='^' || token=='%')
        {
            int op1 = int(s.pop());
            int op2 = int(s.pop());

            int res;

            switch(token)
            {
            case '+':
                res = op1 + op2;
                break;
            case '-':
                res = op1 - op2;
                break;
            case '*':
                res = op1 * op2;
                break;
            case '/':
                res = op1 / op2;
                break;
            case '%':
                res = op1 % op2;
                break;
            case '^':
                res = op1 ^ op2;
                break;
            }
            s.push(res);
        }

        else
        {
            int val;
            cout<<"Enter value for token: "<<char(token);
            cin>>val;
            s.push(char(val));
        }

    }

    s.display();
}
