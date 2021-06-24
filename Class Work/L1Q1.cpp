#include<iostream>
#include<string.h>
using namespace std;

main()
{
    char c[100],d[100],e[100];
    int i,j,k,l=0,n;

    cout<<"Enter string: ";
    cin>>c;

    for(i=0;c[i]!='\0';i++); //length of string c

    cout<<"Length of string is: "<<i<<endl;

    cout<<"Enter string to be concatenated: ";
    cin>>d;

    for(j=0;d[j]!='\0';j++) //concatenate new string to original
        c[j+i] = d[j];

    c[j+i] = '\0';

    cout<<c<<endl;

    cout<<"Enter string to be compared with the above string: ";
    cin>>e;

    //for(k=0;e[k]!='\0';k++);

    for(n=0;c[n]==e[n] && c[n]!='\0';n++);

    if(c[n]==e[n])
        cout<<"Strings are equal";
    else if(c[n]>e[n])
        cout<<"First string > second string";
    else if(c[n]<e[n])
        cout<<"Second string > first string";

    n=i+j;
    cout<<"\nEnter substring to be added to "<<c<<". Also specify its position\n";
    cin>>e;
    cin>>k;

    //j=0; //index = position -1
    k--;
    int n_c = n,m=0;
    for(l=0;e[l]!='\0';l++);

    for(int i=0;i<l;i++)
    {
        c[k+i+l]=c[k+i];
        c[k+i]=e[m];
        m++;
    }
    cout<<c;

    cout<<"\nEnter the substring to be deleted:";
    cin>>e;

    int cl=strlen(c),el=strlen(e);
    int flag=0;
    int pos=-1;


    // SEARCHING FOR THE SUBSTRING IN THE MAIN STRING
    for (int i=0; i<=cl-el;i++){
        for (int j=i;j<i+el;j++){
            flag=1;
            if(c[j]!=e[j-i]){
                flag=0;
                break;
            }
        }
        if(flag==1){
            pos=i;
            break;
        }
    }
    //IF FOUND, DELETING THE SUBSTRING FROM THE MAIN STRING
    if (pos==-1){
        cout<<"Substring not found in string";
        return 0;
    }
    for(int i=0;i<cl-pos;i++){
        c[pos+i]=c[pos+el+i];
    }
    cout<<c;
}
