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
    int data;
    tree* lc;
    tree* rc;

public:
    tree(int ele)
    {
        data=ele;
        lc=rc=NULL;
    }
    tree* create(tree*,int);
    void iterativeInorder(tree*);
    void iterativePreorder(tree*);
    //void iterativePostorder(tree*);
    void levelorder(tree*);
    int printAncestors(tree*,int);
    int findHeight(tree*);
};

tree *root1=NULL;
tree *root_cpy=NULL;

tree* tree::create(tree* root,int x)
{
    tree* temp=new tree(x);
    char dir[30];
    int i;

    tree* curr=root;
    tree* prev=NULL;

    if(root==NULL)
    {
        root=temp;
        return root;
    }

    cout<<"Enter Direction in Uppercase: ";
    cin>>dir;

    for(i=0;i<strlen(dir)&&curr!=NULL;i++)
    {
        prev=curr;
        if(dir[i]=='L')
            curr=curr->lc;
        else
            curr=curr->rc;
    }

    if(curr!=NULL||i!=strlen(dir))
    {
        cout<<"Insertion not possible";
        delete temp;
        return root;
    }

    if(dir[i-1]=='L')
        prev->lc=temp;
    else
        prev->rc=temp;

    return root;
}

void tree::iterativePreorder(tree* root)
{
    if(root==NULL)
        return;

    Stack s;
    tree* temp=root;
    s.push(temp);

    while(s.isEmpty()==0)
    {
        temp=s.pop();

        if(temp==NULL)
            break;

        cout<<temp->data<<" ";

        if(temp->rc!=NULL)
            s.push(temp->rc);
        if(temp->lc!=NULL)
            s.push(temp->lc);
    }
}

void tree::levelorder(tree* root)
{
    if(root==NULL)
        return;

    tree* q[30];
    tree* temp;

    int front=-1,rear=-1;

    q[++rear]=root;

    do
    {
        temp=q[++front];

        cout<<temp->data<<" ";

        if(temp->lc!=NULL)
            q[++rear]=temp->lc;

        if(temp->rc!=NULL)
            q[++rear]=temp->rc;

    }while(front!=rear);
}

void tree::iterativeInorder(tree* root)
{
    if(root==NULL)
        return;

    Stack s;
    tree* temp=root;

    while(1)
    {
        for(;temp!=NULL;temp=temp->lc)
        {
            s.push(temp);
        }

        temp=s.pop();

        if(temp==NULL)
            break;

        cout<<temp->data<<" ";

        temp=temp->rc;
    }
}

int tree::printAncestors(tree* root,int x)
{
    if(root==NULL)
        return 0;

    if(root->data==x)
        return 1;

    if(printAncestors(root->lc,x)||printAncestors(root->rc,x))
    {
        cout<<root->data<<" ";
        return 1;
    }

    return 0;
}

int max(int a,int b)
{
    return((a>b)?a:b);
}

int tree::findHeight(tree* root)
{
    if(root==NULL)
        return(0);
    return(max(findHeight(root->lc),findHeight(root->rc))+1);
}

main()
{
    tree d(0);
    int ch,x;

    do
    {
        cout<<"\n1.Insert\t2.Ancestors\t\t3.Display\n4.Height\t5.Parents\t\t6.Exit\n";
        cout<<"Enter Desired Value: ";
        cin>>ch;

        switch(ch)
        {
        case 1:
            cout<<"Enter Element: ";
            cin>>x;
            root1=d.create(root1,x);
            break;
        case 2:
            cout<<"\nEnter node who's ancestors are to be found: ";
            cin>>x;
            d.printAncestors(root1,x);
            break;
        case 3:
            d.levelorder(root1);
            cout<<"\n";

            d.iterativePreorder(root1);
            cout<<"\n";

            d.iterativeInorder(root1);
            cout<<"\n";

            break;
        case 4:
            x=d.findHeight(root1);
            cout<<"Height of tree = "<<x<<endl;
            break;
        case 5:
            cout<<"\nEnter value to be searched: ";
            cin>>x;
            //Parents
            break;
        case 6:
            break;
        default:
            cout<<"\nInvalid Response\n";
        }
    }while(ch!=6);
}
