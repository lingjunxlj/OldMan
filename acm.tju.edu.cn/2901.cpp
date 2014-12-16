#include <iostream>
#include <cmath>
using namespace std;
const int MAXV = 100000; 
bool flag[MAXV+1]; 
long long prime[MAXV+1]; 
int size; 
long long a[4000]={1},b[4000],c[4000];
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


int main()
{
    long long i,j;
    a[0]=1;
    for (i=1;i<=4000;i++)
    a[i]=a[i-1]*i;
    
    genPrime(MAXV);
    cout<<prime[1];
    long long n,r;
    while (cin>>n>>r)
    {                       
        long long s;
        s=a[n]/(a[r]*a[n-r]) ;        
        j=0;
        i=0;
        while(s>0)
        {
            
            if (s%prime[i]==0)
            {
                s=s/prime[i];
                c[j]=prime[i];
                
                j++;
                
            }
            if (s%prime[i]!=0)
            i++;
        }
        printf("%d", c[0]);
        for (i=1;i<j;i++) 
        printf(" * %d", c[i]);
        putchar('\n');
    }
}
            
        
        
        
        
        



