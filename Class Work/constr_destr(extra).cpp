#include<iostream>
using namespace std;

class info
{
private:
    char name[20];
public:

    int count_const=0,count_dest=0;

    info()
    {   cout<<"Inside Constructor"<<endl;
        count_const=count_const+1;
    }

    ~info()
    {   cout<<"Inside Destructor";
        count_dest=count_dest+1;
    }

    out()
    {
        cout<<"Created: "<<count_const;
        cout<<"Destroyed: "<<count_dest;
    }
};

main()
{
    info student,teacher,assistant;

    student.out();
}
