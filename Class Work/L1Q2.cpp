#include<iostream>
using namespace std;

class Student
{
    char name[50];
    int rollNumber;
    char grade;
public:
    void read(Student s[],int n)
    {
        for(int i=0;i<n;i++)
        {
            cout<<"Enter name, roll number and grade for student "<<i+1<<": ";
            cin>>s[i].name;
            cin>>s[i].rollNumber;
            cin>>s[i].grade;
        }
    }

    void display(Student s[],int n)
    {
        for(int i=0;i<n;i++)
        {
            cout<<"Student"<<(i+1)<<": ";
            cout<<s[i].name<<"\t";
            cout<<s[i].rollNumber<<"\t";
            cout<<s[i].grade<<"\n";
        }
    }

    void sort(Student s[],int n)
    {
        cout<<"\nSorting...\n";
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<n-i-1;j++)
            {
                if(s[j].rollNumber>s[j+1].rollNumber)
                {
                    Student t = s[j];
                    s[j] = s[j+1];
                    s[j+1] = t;
                }
            }
        }
    }
};

main()
{
    int n;

    cout<<"Enter number of students in class: ";
    cin>>n;

    Student a[100],d;
    d.read(a,n);
    d.display(a,n);
    d.sort(a,n);
    d.display(a,n);
}
