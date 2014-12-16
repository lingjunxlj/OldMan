#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int x,y;
    cin>>x;
    while (x--)
    {
        cin>>y;
        int i,a[20]={0};
        for (i=0;i<y;i++)
        a[i]=i+1;
        do
        {
            for (i=0;i<y;i++)
            cout<<a[i];
            cout<<endl;
            
        }while (next_permutation (a,a+y));
    }cout<<endl;
}
        
