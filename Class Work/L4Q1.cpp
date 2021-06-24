#include<iostream>
#include<string.h>
#define maxx 1000
using namespace std;

class Stack
{
private:
    int top;
public:
    int a[maxx];

    Stack()
    {
        top=-1;
    }

    int isFull()
    {
        if(top==maxx-1)
            return 1;
        else
            return 0;
    }

    int isEmpty()
    {
        if(top==-1)
            return 1;
        else
            return 0;
    }

    void push(char x)
    {
        if(isFull())
            cout<<"Stack full"<<endl;
        else
                a[++top]=x;
    }

    char pop()
    {
        if(isEmpty())
            cout<<"Stack is empty"<<endl;
        else
            return a[top--];
    }

    char topEle()
    {
        if(top!=-1)
            return a[top];
        else if(top==-1)
            return 0;
    }
};

int prec(char x) //precedence
    {
        if(x=='^')
            return 3;
        else if(x=='*'||x=='/')
            return 2;
        else if(x=='+'||x=='-')
            return 1;
        else if((x>=65&&x<=90)||(x>=97&&x<=122))//operands A-Z and a-z
            return 0;
        else if(x=='(')
            return -1;
    }

main()
{
    char input[][100]={"(((a+b)-c)*(d^(e^f)))/g","a+b*c-d","a*b+c/d","a*(b+c)/d","a*(b+c/d)","(a*b)+(c/d)","(a*(b+c))/d","a+b*c/d-e","(a+b)*c/d-e","(a+b)*(c-d)/(e+f)","(a+b)*(c-d)/((e-f)*(g+h))","a+b*c-d/e*f","a/b^c+d*e-f*g"};
    int i;
    Stack s;

    for(int k=0;k<13;k++)
    {
        cout<<input[k]<<" -> ";
        for(i=0;i<strlen(input[k]);i++)
        {
            if((s.isEmpty()==1 && input[k][i]!='(' && prec(input[k][i])!=0))//when empty, push incoming OPERATOR ONLY. Do not push operands or ')'
                s.push(input[k][i]);
            else if(prec(input[k][i])>prec(s.topEle()) && prec(input[k][i])!=0 && input[k][i]!=')')//pushing OPERATOR only when PRECEDENCE HIGHER
                s.push(input[k][i]);
            else if(input[k][i]=='(')//when we encounter this we want to PUSH it IRRESPECTIVE of anything else
                s.push(input[k][i]);
            else if(prec(input[k][i])==0)//printing operands
                cout<<input[k][i];
            else if(input[k][i]==')')
            {
                while(s.topEle()!='(')//pop until we encounter '('
                    cout<<s.pop();
                s.pop(); //popping the parenthesis too
            }
            else if((s.isEmpty()==0) && prec(input[k][i])<=prec(s.topEle()))
            {
                while((s.isEmpty()==0) && prec(input[k][i])<=prec(s.topEle()))
                    cout<<s.pop();
                s.push(input[k][i]);

            }
        }

        while(s.isEmpty()!=1)
            cout<<s.pop();

        cout<<endl;
    }
}
