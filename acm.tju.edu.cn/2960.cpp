#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;
int JC(int y)
{
    int i,sum=1;

    
        for (i=0;i<y;i++)
        sum=sum*10;
        return sum;
    
}
int main()
{
    char a[100];
    int b[100],i;
    memset(b,0,sizeof (b));
    cin>>a;
    int min=0,len=strlen(a);
    for (i=0;i<len;i++)
    min=min+(a[len-1-i]-'0')*JC(i);
    int sum,k=0;
    do
    {
        sum=0;
        for (i=0;i<len;i++)
        {
            sum+=(a[len-1-i]-'0')*JC(i);
            
            if (sum>min)
            b[k++]=sum;
        }
    }while (next_permutation (a,a+len));
    sort(b,b+k);
    if (b[0]==0)
    cout<<0<<endl;
    else
    cout<<b[0]<<endl;
    system("pause");
}
    
