#include<iostream>
#include<iomanip>
using namespace std;
int a[10001];
int main()
{
     int n;
     unsigned long t=1;
     a[0]=1;
     for(int i=1;i<10001;i++) 
     { 
        t*=i;
        while((t%10)==0) 
        t/=10;
        t%=100000;
        a[i]=t%10;
     }
     while(cin>>n)
     {
         int r;
         r=a[n];
         cout<<setw(5)<<n<<" -> "<<r<<endl;
     }
	 return 0;
}
