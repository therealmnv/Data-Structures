#include<iostream>
using namespace std;
main(){
int i,j,a[10],imin,n,temp;

cout<<"No of elements: ";
cin>>n;

for(i=0;i<n;i++)
{
    cin>>a[i];
}

for(i=0;i<n-1;i++){
    imin = i;
    for(j=i+1;j<n;j++){
        if(a[j]<a[imin])
            {
                imin=j;
            }
    }
    temp = a[i];
    a[i] = a[imin];
    a[imin] = temp;
}

for(i=0;i<n;i++)
{
    cout<<a[i]<<" ";
}
}
