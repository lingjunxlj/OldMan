#include <iostream>
using namespace std;
#define MAX 1<<30
const int MAXV = 999999; 
bool flag[MAXV+1];
long long prime[MAXV+1],divisor[MAXV+1];
int size; 
void genPrime(int max)
{
    memset(flag, true, sizeof(flag));
    for(int i = 2; i <= max / 2; i++)
    {
        if(flag[i])
        {
            for(int j = i << 1 ; j <= max; j += i)
            {
                flag[j] = false;
            }
        }
    }
    for(int i = 2 ; i <= max; i++)
    {
        if(flag[i])
        {
            prime[size++] = i;
        }
    }
}
void countDivisor()
{
    int i, k, count=1,j=0,l=0,max=1<<30;
    while (max--)
    {
        l++;
        for (i=0; l>1 ; i++)
        {
            if (l%prime[i]!=0) 
            continue;
            k=1;
            while (l%prime[i]==0)
            {
                k++;
                l/=prime[i];
            }
            count*=k;
            if (l<prime[i]) break;
        }
        divisor[l]=count;
    }
    
}
int main()
{
    long long x,y;
    genPrime(MAXV);
    countDivisor();
    while (cin>>x>>y)
    {
        if (x==0&&y==0)
        break;
        long long sum=0,i;
        for (i=x;i<=y;i++)
        {
            sum+=divisor[i];
        }
        cout<<sum<<endl;
    }
}
    
        
        
        
