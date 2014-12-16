#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int x;
    cin>>x;
    while (x--)
    {
        int i,value[10],sum,max;
        max=sum=0;
        for (i=0;i<10;i++)
        {
            cin>>value[i];
            sum+=value[i];
        }       
        sort(value,value+10);
        for (i=0;i<10;i++)
        {
            max+=value[i];
            if (max*2==(sum))
            {
                cout<<max<<endl;
                break;
            }
            if (max*2>(sum))
            {
                if (sum-max>max-value[i])
                max=sum-max;
                else
                max=max-value[i];
                cout<<max<<endl;
                break;
            }
            
        }
        
    }
}
        
