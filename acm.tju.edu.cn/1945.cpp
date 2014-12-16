#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    int a=0,b,c,d;
    while(1)
    {
        a++;
        if (a>200)
        break;
        int i,sum[300];
        for (i=0;i<=a;i++)
        sum[i]=i*i*i;
        for (b=2;b<a;b++)
        {
            if (sum[a]<sum[b]+sum[b+1]+sum[b+2])
            break;
            
                for (c=b+1;c<a;c++)
                {
                    if (sum[a]<sum[b]+sum[c]+sum[c+1])
                    break;
                    
                        for (d=c+1;d<a;d++)
                        if (sum[a]==sum[b]+sum[c]+sum[d])
                        printf ("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);
                    
                }
            
        }
    }
    system("pause");
}
