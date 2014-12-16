#include <iostream>
#include <cmath>
using namespace std;
long long f(long long  a,long long  k)
{
     long long sum;
     if(k==1) return a;
     sum=f(a,k/2);
     sum=sum*sum%200907;
     if(k%2==1) sum=sum*a%200907;
     return sum%200907;
}

int main()
{
    long long x;
    cin>>x;
    while (x--)
    {
        long long a[4],i,k;
        for (i=0;i<4;i++)
        cin>>a[i];
        if ((a[1]-a[0])==(a[2]-a[1]))
        {
            k=(a[1]-a[0])%200907*(a[3]-1)%200907+a[0]%200907;
            k%=200907;
            cout<<k<<endl;
        }
        else if (a[1]/a[0]==a[2]/a[1])
        {
            
            
            long long b,d,t,l,y,m;
            d=1;
            y=0;
            m=1;
            l=a[1]/a[0];
            t=a[1]/a[0] ;
            b=a[3]-1;                                        
               
            
            cout<<f(l,a[3]-1)*a[0]%200907<<endl;
        }
    }
}
        
