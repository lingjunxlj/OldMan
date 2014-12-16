#include <iostream>
using namespace std;
int a[1001];
int NFA( )
{
    int i,j,s,k=0;
    for (i=1;i<=1000;i++)
    {
        s=s*i;
        for (j=1;;j++)
        {
            if (s%(j*10)!=0)
            {
                a[i]=s/((j-1)*10)%10;               
                break;
            }
        }
    }
}
int main()
{
    NFA();
    int x;
    while (cin>>x)
    {
        cout<<a[x]<<endl;
    }
}
    
            
        
        
        
        
        
        
