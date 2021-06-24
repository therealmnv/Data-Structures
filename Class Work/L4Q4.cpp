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
        else if((x>=65&&x<=90)||(x>=97&&x<=122))//operands
            return 0;
        else if(x==')')
            return -1;
    }

main()
{
    char input[][100]={"a+b*c-d","a*b+c/d","a*(b+c)/d","a*(b+c/d)","(a*b)+(c/d)","(a*(b+c))/d","a+b*c/d-e","(a+b)*c/d-e","(a+b)*(c-d)/(e+f)","(a+b)*(c-d)/((e-f)*(g+h))","a+b*c-d/e*f","a/b^c+d*e-f*g"};
    int i;
    Stack s;

for(int k=0;k<12;k++)
{
    cout<<input[k]<<" -> ";
    char output[100],temp;
    int j=0;
    for(i=strlen(input[k])-1;i>-1;i--)
    {
        if((s.isEmpty()==1 && prec(input[k][i])!=0) && input[k][i]!='(')
            s.push(input[k][i]);
        else if(prec(input[k][i])>prec(s.topEle()) && prec(input[k][i])!=0 && input[k][i]!='(')
            s.push(input[k][i]);
        else if(input[k][i]==')')
            s.push(input[k][i]);
        else if(prec(input[k][i])==0) //printing operand
            output[j++]=input[k][i];
        else if(input[k][i]=='(')
        {
            while(s.topEle()!=')')
                output[j++]=s.pop();
            s.pop(); //removing the parenthesis
        }
        else if((s.isEmpty()==0) && prec(input[k][i])<=prec(s.topEle())&& input[k][i]!='(')
        {
            int flag = 0;
            while((s.isEmpty()==0) && prec(input[k][i])<=prec(s.topEle()))
            {
                if(((input[k][i]=='*' && s.topEle()=='/') || (input[k][i]=='/' && s.topEle()=='*')) || (input[k][i]=='+' && s.topEle()=='-') || (input[k][i]=='-' && s.topEle()=='+'))
                {
                    s.push(input[k][i]);
                    flag = 1;
                    break;
                }
                else
                    output[j++]=s.pop();
            }
            if(flag==0)
                s.push(input[k][i]);
        }
    }

    while(s.isEmpty()!=1)
            output[j++]=s.pop();

    output[j]='\0';

    for(i=0;i<j/2;i++)
    {
        temp=output[i];
        output[i]=output[j-i-1];
        output[j-i-1]=temp;
    }

    cout<<output;
    cout<<endl;
}

}
