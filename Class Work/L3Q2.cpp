#include<iostream>
using namespace std;

class Sparse
{
private:
    int row,column,value;
public:
    Sparse()
    {
        row=column=value=0;
    }
    Sparse(int r,int c,int v)
    {
        row=r;
        column=c;
        value=v;
    }
    void fastTranspose(Sparse a[])
    {
        Sparse b[20];

        b[0].row = a[0].column;
        b[0].column = a[0].row;
        b[0].value = a[0].value;

        int rowTerm[20],startPosition[20];

        for(int i=0;i<a[0].column;i++)
            rowTerm[i]=0;

        for(int i=1;i<=a[0].value;i++)
            rowTerm[a[i].column]++;

        startPosition[0]=1;

        for(int k=1;k<a[0].column;k++)
            startPosition[k]=startPosition[k-1]+rowTerm[k-1];

        for(int i=1;i<=a[0].value;i++)
        {
            b[startPosition[a[i].column]].row = a[i].column;
            b[startPosition[a[i].column]].column = a[i].row;
            b[startPosition[a[i].column]].value = a[i].value;
            startPosition[a[i].column]++;
        }
        Sparse d;
        d.display(b);
    }

    void display(Sparse a[])
    {
        cout<<endl<<"Displaying..."<<endl;

        for(int i=1;i<=a[0].value;i++)
            cout<<a[i].row<<"\t"<<a[i].column<<"\t"<<a[i].value<<"\n";
    }
};

main()
{
    Sparse s[20];
    int r,c,v,val;

    cout<<"Enter the no. of rows:\n";
    cin>>r;
    cout<<"Enter the no. of cols:\n";
    cin>>c;
    cout<<"Enter the no. of values:\n";
    cin>>v;

    s[0]=Sparse(r,c,v);

    cout<<"Enter the elements of the sparse matrix:\n";

    for(int i=1;i<=v;i++)
    {
        cout<<"\nRow "<<i<<": ";
        cin>>r;
        cout<<"\nCol "<<i<<": ";
        cin>>c;
        cout<<"\nValue "<<i<<": ";
        cin>>val;

        s[i]=Sparse(r,c,val);
    }
    //s[0].display(s);
    s[0].fastTranspose(s);
}
