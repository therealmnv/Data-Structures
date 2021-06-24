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

    void disp(sparse* c)
    {
        for(int i=0;i<=c[0].val;i++)
        {
            cout<<"Row\tCol\tValue\n";
            cout<<c[i].row<<'\t'<<c[i].col<<'\t'<<c[i].val<<endl;
        }
        return;
    }

    void fast_transpose(sparse* a)
    {
        sparse b[20];
        int rowterm[20],start_pos[20];
        int x;

        b[0].row=a[0].col;
        b[0].col=a[0].row;
        b[0].val=a[0].val;

        for(int i=0;i<a[0].col;i++) //INITIALIZE TO 0
            rowterm[i]=0;

        for(int i=1;i<=a[0].val;i++)
            rowterm[a[i].col]++;

        start_pos[0]=1;

        for(int i=1;i<=a[0].col;i++)
            start_pos[i]=start_pos[i-1]+rowterm[i-1];

        for(int i=1;i<a[0].col;i++)
        {
            int x=start_pos[a[i].col];
            b[x].row=a[i].col;
            b[x].col=a[i].row;
            b[x].val=a[i].val;
            start_pos[a[i].col]++;
        }

        cout<<"OUTPUT USING FAST TRANSPOSE:\n";
        disp(b);
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
        cout<<i<<endl;

        cout<<"\nRow: ";
        cin>>r;
        cout<<"\nCol: ";
        cin>>c;
        cout<<"\nValue: ";
        cin>>v;

        s[i]=sparse(r,c,v);
    }

    d.fast_transpose(s);
}
