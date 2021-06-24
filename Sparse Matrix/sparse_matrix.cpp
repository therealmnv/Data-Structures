#include<iostream>
using namespace std;

class sparse
{
private:
    int row,col,val;

public:
    sparse()
    {
        row=0;
        col=0;
        val=0;
    }

    sparse(int r,int c,int v)
    {
        row=r;
        col=c;
        val=v;
    }

    void disp(sparse* a)
    {
        for(int i=1;i<=a[0].val;i++)
        {
            cout<<"Row\tCol\tValue\n";
            cout<<a[i].row<<'\t'<<a[i].col<<'\t'<<a[i].val<<endl;
        }
    }
};

main()
{
    sparse s[20],d;
    int r,c,v,n;

    cout<<"Enter the no. of rows:\n";
    cin>>r;
    cout<<"Enter the no. of cols:\n";
    cin>>c;
    cout<<"Enter the no. of values:\n";
    cin>>v;

    s[0]=sparse(r,c,v);

    cout<<"Enter the elements of the sparse matrix:\n";
    n=v;

    for(int i=1;i<=n;i++)
    {
        cout<<"\nRow: ";
        cin>>r;
        cout<<"\nCol: ";
        cin>>c;
        cout<<"\nValue: ";
        cin>>v;

        s[i]=sparse(r,c,v);
    }

    d.disp(s);
}
