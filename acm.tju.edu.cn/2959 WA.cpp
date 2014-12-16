#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    int x,y;
    cin>>x>>y;
    int i,num[x];
    for (i=0;i<x;i++)
    cin>>num[i];
    int n,m,mid,sum=1;
    for (i=0;i<x;i++)
    if (num[i]==y)
    mid=i;
    n=m=mid;
    while (n>=0&&m<x)
    {
        if ((num[n--]+num[m++])/2==y)
        sum++;
    }
    cout<<sum<<endl;
    system("pause");
}
    
