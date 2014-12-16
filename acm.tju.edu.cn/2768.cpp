#include <iostream>
using namespace std;
int main()
{
    int s,n;
    cin>>s>>n;
    int coin[n],i,max=0;
    for (i=0;i<n;i++)
    cin>>coin[i];
    sort(coin,coin+n);
    for (i=0;i<n;i++)
    {
        while (s>0)
        {
            s-=coin[n-1-i];
            max++;
        }
        if (s<0)
        {
            s+=coin[n-1-i];
            max--;
        }
    }
    cout<<max<<endl;
    while (1);
}
        
    
