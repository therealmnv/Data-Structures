#include<iostream>
#include<string.h>
#define maxx 50
using namespace std;

class Stack
{
private:
    int top;
    char A[maxx][maxx];
public:
    Stack()
    {
        top = -1;
    }
    void push(char []);
    char *pop();
};
    void Stack::push(char x[])
    {
        if(top==maxx-1)
            cout<<"Stack is full"<<endl;
        else
        {
            top = top + 1;
            strcpy(A[top],x);
        }
    }

    char *Stack::pop()
    {
        if(top==-1)
            cout<<"Stack is empty"<<endl;
        else
            return A[top--];
    }

main()
{
    char a[30],op1[20],op2[20];
    Stack s;

    cout<<"Enter character prefix: ";
    cin.get(a,30);

    for(int i=strlen(a)-1;i>=0;i--)
    {
        char temp[20],t[20];
        temp[0]=a[i];
        temp[1]='\0';

        char token = a[i];

        if(token=='+' || token=='-' || token=='*' || token=='/' || token=='^' || token=='%')
        {
            strcpy(op1,s.pop());
            strcpy(op2,s.pop());
            strcpy(t,op1);
            strcat(t,op2);
            strcat(t,temp);
            s.push(t);
        }

        else
        {
            s.push(temp);
        }

    }

    strcpy(a,s.pop());
    cout<<a;
}
