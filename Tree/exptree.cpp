#include<iostream>
#include<string.h>
using namespace std;

class tree;

class Stack
{
    int top;
    int stackSize;
    tree* a[100];
public:
    Stack()
    {
        top=-1;
        stackSize=100;
    }

    int isEmpty()
    {
        if(top==-1)
            return 1;
        else
            return 0;
    }

    int isFull()
    {
        if(top+1==stackSize)
            return 1;
        else
            return 0;
    }

    void push(tree* node)
    {
        if(isFull()==1)
            return;
        else
            a[++top]=node;
    }

    tree* pop()
    {
        if(isEmpty()==1)
            return NULL;
        else
            return a[top--];
    }
};

class tree
{
public:
    char data;
    tree* lc;
    tree* rc;

    tree* create(char);
    void inorder(tree*);
    int eval(tree*);

    tree(char ele)
    {
        data=ele;
        lc=rc=NULL;
    }
};

tree* tree::create(char x)
{
    tree* temp=new tree(x);
    return temp;
}

void tree::inorder(tree* t)
{
    if(t!=NULL)
    {
        inorder(t->lc);
        cout<<t->data;
        inorder(t->rc);
    }
    return;
}

int tree::eval(tree* root)
{
    if(root==NULL)
        return 0;
    if(root->lc==NULL && root->rc==NULL)
        return ((root->data)-48);
    int l_val=eval(root->lc);
    int r_val=eval(root->rc);

    if(root->data=='+')
        return l_val+r_val;
    if(root->data=='-')
        return l_val-r_val;
    if(root->data=='*')
        return l_val*r_val;
    if(root->data=='/')
        return l_val/r_val;
    if(root->data=='%')
        return l_val%r_val;
    if(root->data=='^')
        return l_val^r_val;

}

tree* root1=NULL;

main()
{
    Stack s;
    char a[100];
    tree d(0);
    tree* left=NULL;
    tree* right=NULL;

    int i;

    cout<<"Enter postfix";
    cin>>a;

    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]-48<10 && a[i]-48>=0)
            s.push(d.create(a[i]));
        else
        {
            root1=d.create(a[i]);
            root1->rc=s.pop();
            root1->lc=s.pop();
            s.push(root1);
        }
    }

    d.inorder(root1);
    i=d.eval(root1);
    cout<<"\nAfter evaluating\n"<<i;
}
