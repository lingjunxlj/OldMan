#include <iostream>
using namespace std;
#define MAX 109
long long a[1000];
void First()
{
    long long i;
    a[0]=1;
    for (i=0;i<MAX;i++)
    a[i+1]=a[i]+i;
}
int main()
{
    int x;
    First();

    while (cin>>x)
    {
        long long sum,i,j;
        for (i=1;;i++)
        {
            if (a[i]<=x&&a[i+1]>x)
            {               
                cout<<i%10<<endl;
                break;
            }
        }
    }
}
    
    
