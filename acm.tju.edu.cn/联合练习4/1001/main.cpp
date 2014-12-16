#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int t,x=0;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        x++;
        if (n==1)
        {
            printf("Case %d: %d\n",x,1);
            continue;
        }

        if (n==2)
        {
            printf("Case %d: %d\n",x,2);
            continue;
        }

        //if (n%2 ==1)
        //printf("Case %d: %d\n",x,(n+1));
        //if (n%2 == 0)
        //printf("Case %d: %d\n",x,n-1);
        printf("Case %d: %d\n",x,2*n-4);

    }
}
