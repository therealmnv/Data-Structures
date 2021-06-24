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

    void slow_transpose(sparse* a)
    {
        sparse b[20];
        int x=1;

        for(int i=0;i<a[0].col;i++)
        {
            for(int j=1;j<=a[0].val;j++)
            {
                if(i==a[j].col)
                {
                    b[x].row=a[j].col;
                    b[x].col=a[j].row;
                    b[x].val=a[j].val;
                    x++;
                }
            }
        }

        b[0].row=a[0].col;
        b[0].col=a[0].row;
        b[0].val=a[0].val;

        cout<<"INPUT SPARSE MATRIX IS:\n";
        disp(a);
        cout<<"OUTPUT USING SLOW TRANSPOSE:\n";
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

    d.slow_transpose(s);
}
