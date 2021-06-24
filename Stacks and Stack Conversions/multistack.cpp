#include<iostream>
using namespace std;
#define max 9

class multistack
{
private:
    int top[10],bottom[10],a[max];
public:
    multistack(int n_stk)
    {
        for(int i=0;i<n_stk;i++)
        {
            top[i]=(max/n_stk)*i-1;
            bottom[i]=top[i]+1;
        }
    }

    int isEmpty(int stk)
    {
        if(top[stk]<bottom[stk])
        {
            cout<<"Empty stack\n";
            return 1;
        }
        else
            return 0;
    }

    int isFull(int stk)
    {
        if((top[stk]==(bottom[stk+1] - 1)) || ((top[stk]+1)==max))
        {
            cout<<"Stack overflow\n";
            return 1;
        }
        else
            return 0;
    }

    void push(int stk,int ele)
    {
        if(isFull(stk)==0)
        {
            a[++top[stk]]=ele;
            cout<<"Stack: "<<stk<<" Pushed element: "<<ele<<endl;
        }
    }

    void pop(int stk)
    {
        if(isEmpty(stk)==0)
            top[stk]--;
    }
};

main()
{
    int x;
    multistack ms(3);
    x=ms.isEmpty(1);
    ms.isEmpty(2);
    ms.push(1, 101);
    ms.push(1,101);
    ms.push(1,101);
    ms.push(1,101);
    ms.pop(1);
    ms.pop(1);
    ms.pop(1);
    ms.isEmpty(1);
    ms.pop(1);

}
