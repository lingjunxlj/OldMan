#include <iostream>
#include <string>
using namespace std;
int a[20]={0,2,4,6,30,32,34,36,40,42,44,46,50,52,54,56,60,62,64,66};
int main()
{
    int x,flag;
    while (cin>>x&&x!=0)
    {
        int i,j,l,b[100];
        l=0;
        while (x>0)
        {
            b[l]=x%20;
            x/=20;
            l++;
        }
        flag=0;
        if (l>=8)
        flag=1;
        l=l-1;
        cout<<a[b[l]];
        
        for (i=l-1;i>=0;i--)
        {
            if (i==6&&flag==1)
            cout<<",000,000";
            printf (",%.3d",a[b[i]]);
        }
        cout<<endl;
    }
}
