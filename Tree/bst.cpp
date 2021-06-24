#include<iostream>
using namespace std;

class bst
{
    int data;
    bst* lc;
    bst* rc;

public:
    bst(int ele)
    {
        data=ele;
        lc=rc=NULL;
    }
    bst* ins(bst*);
    bst* minRightSub(bst*);
    void dispInOrder(bst*);
    void dispPreOrder(bst*);
    void dispPostOrder(bst*);
    void normalSearch(bst*);
    void del(bst*,int);
    void recSearch(bst*,int);
};

bst* root1=NULL;

bst* bst::ins(bst* root)
{
    int x,flag;
    cout<<"\nEnter value to be inserted: ";
    cin>>x;

    bst* temp=new bst(x);
    bst* prev=NULL;

    if(root==NULL)
        root=temp;
    else
    {
        bst* curr=root;

        while(curr!=NULL)
        {
            prev=curr;

            if(x>=curr->data)
            {
                curr=curr->rc;
                flag=0;
            }
            else
            {
                curr=curr->lc;
                flag=1;
            }
        }

        if(flag==0)
            prev->rc=temp;

        else
            prev->lc=temp;
    }
    return root;
}

void bst::dispInOrder(bst* t)
{
    if(t!=NULL)
    {
        dispInOrder(t->lc);
        cout<<t->data<<" ";
        dispInOrder(t->rc);
    }
}

void bst::dispPreOrder(bst* t)
{
    if(t!=NULL)
    {
        cout<<t->data<<" ";
        dispPreOrder(t->lc);
        dispPreOrder(t->rc);
    }
}

void bst::dispPostOrder(bst* t)
{
    if(t!=NULL)
    {
        dispInOrder(t->lc);
        dispInOrder(t->rc);
        cout<<t->data<<" ";
    }
}

void bst::normalSearch(bst* root)
{
    int x,flag=0;
    cout<<"\nEnter value to be searched: ";
    cin>>x;

    bst* curr=root;

    if(root==NULL)
        cout<<"\nBinary Search Tree Empty...\n";
    else
    {
        while(curr!=NULL)
        {
            if(curr->data==x)
            {
                cout<<"Element found";
                flag=1;
                break;
            }
            else if(x>curr->data)
                curr=curr->rc;
            else if(x<curr->data)
                curr=curr->lc;
        }

        if(flag==0)
            cout<<"\nElement Not Found...\n";
    }
}

void bst::recSearch(bst* t,int x)
{
    if(t!=NULL)
    {
        if(t->data==x)
        {
            cout<<"\nRecursively Found\n";
            return;
        }

        else if(x>t->data)
            return recSearch(t->rc,x);

        else if(x<t->data)
            return recSearch(t->lc,x);
    }

    cout<<"Element Not Found Recursively";
}

bst* bst::minRightSub(bst* t)
{
    bst* curr=t;
    while(curr->lc!=NULL)
    {
        curr=curr->lc;
    }
    return curr;
}

void bst::del(bst* root,int x)
{
    int flag=0;

    bst* curr=root;
    bst* prev=NULL;

    if(curr==NULL)
        cout<<"\nBinary Search Tree Empty...\n";

    else
    {
        while(curr->data!=x)
        {
            prev=curr;

            if(x>curr->data)
                curr=curr->rc;
            else if(x<curr->data)
                curr=curr->lc;
        }

        if(curr->lc==NULL && curr->rc==NULL)
        {
            if(prev->rc==curr)
                prev->rc=NULL;
            else
                prev->lc=NULL;

            delete(curr);
            flag=1;
        }

        else if(curr->lc==NULL && curr->rc!=NULL)
        {
            if(prev->rc==curr)
                prev->rc=curr->rc;
            else
                prev->lc=curr->rc;

            delete(curr);
            flag=1;
        }

        else if(curr->lc!=NULL && curr->rc==NULL)
        {
            if(prev->rc==curr)
                prev->rc=curr->lc;
            else
                prev->lc=curr->lc;

            delete(curr);
            flag=1;
        }

//MINIMUM ON RIGHT SUBTREE
        else if(curr->lc!=NULL && curr->rc!=NULL)
        {
            bst* substitution;
            substitution=minRightSub(curr->rc);

            int val;
            val=substitution->data;

            del(root,val);

            curr->data=val;
            flag=1;
        }
    }

    if(flag==0)
        cout<<"\nElement not present\n";
}

main()
{
    bst d(0);
    int ch,x;

    do
    {
        cout<<"\n1.Insert\t2.Delete\t\t3.Display\n4.Search\t5.Recursive Search\t6.Exit\n";
        cin>>ch;

        switch(ch)
        {
        case 1:
            root1=d.ins(root1);
            break;
        case 2:
            cout<<"\nEnter value to be deleted: ";
            cin>>x;
            d.del(root1,x);
            break;
        case 3:
            //d.dispInOrder(root1);
            d.dispPreOrder(root1);
            break;
        case 4:
            d.normalSearch(root1);
            break;
        case 5:
            cout<<"\nEnter value to be searched: ";
            cin>>x;
            d.recSearch(root1,x);
            break;
        case 6:
            break;
        default:
            cout<<"\nInvalid Response\n";
        }
    }while(ch!=6);
}
