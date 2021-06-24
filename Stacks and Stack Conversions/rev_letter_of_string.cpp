#include<iostream>
#include<string.h>
using namespace std;
char reverse(char A[])
{
    int i,j=0,k=0;
    char a[20];

    for(i=0;A[i]!='\0';i++)
    {
        k=0;
    }
    i--;
    while(A[i]!=' ')
    {
        a[j] = A[i];
        j++;
        i--;
    }
    i++;
    a[j+1]='\0';
    cout<<a;
}


main()
{
    char A[]="Manipal institute of technology";
    reverse(A);

}
