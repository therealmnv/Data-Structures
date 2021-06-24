#include<iostream>
using namespace std;

class tree
{
    int data;
    tree* lc;
    tree* rc;

public:
    tree* create();
    void inorder(tree*);
    void preorder(tree*);
    void postorder(tree*);
    tree* copyy(tree*);
};

tree *root=NULL;
tree *root_cpy=NULL;

tree* tree::create()
{
    int x;
    tree* temp;

    cout<<"Enter -1 to exit: ";
    cin>>x;

    if(x==-1)
        return NULL;

    temp=new tree;
    temp->data=x;

    cout<<"Enter Left Child of "<<x<<": ";
    temp->lc=create();

    cout<<"Enter Right Child of "<<x<<": ";
    temp->rc=create();

    return temp;
}

void tree::preorder(tree* t)
{
    if(t!=NULL)
    {
        cout<<t->data<<" ";

        preorder(t->lc);
        preorder(t->rc);
    }
    return;
}

void tree::postorder(tree* t)
{
    if(t!=NULL)
    {
        postorder(t->lc);
        postorder(t->rc);
        cout<<t->data<<" ";
    }
    return;
}

void tree::inorder(tree* t)
{
    if(t!=NULL)
    {
        inorder(t->lc);
        cout<<t->data<<" ";
        inorder(t->rc);
    }
    return;
}

tree* tree::copyy(tree* t)
{
    if(t!=NULL)
    {
        tree* temp;
        temp=new tree;

        temp->data=t->data;

        temp->lc=copyy(t->lc);
        temp->rc=copyy(t->rc);

        return temp;
    }

    return NULL;
}

main()
{
    tree d;
    int ch;

    do
    {
        cout<<"1.Create\t2.Inorder\t3.Preorder\n4.Postorder\t5.Copy\t\t6.Exit";
        cin>>ch;

        switch(ch)
        {
        case 1:
            root=d.create();
            break;
        case 2:
            d.inorder(root);
            break;
        case 3:
            d.preorder(root);
            break;
        case 4:
            d.postorder(root);
            break;
        case 5:
            root_cpy=d.copyy(root);
            d.inorder(root_cpy);
            break;
        case 6:
            break;
        default:
            cout<<"Invalid Response";
        }
    }while(ch!=6);
}
