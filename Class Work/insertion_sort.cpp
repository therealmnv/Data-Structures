#include<iostream>
using namespace std;
main()
{
    int i,n,hole,a[10],value;

    cout<<"No of elements: ";
    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(i=1;i<n;i++)
    {
        value = a[i];
        hole = i;
        while(hole>0 && a[hole-1]>value)
        {
            a[hole] = a[hole-1];
            hole--;
        }
        a[hole]=value;
    }

    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }

}
