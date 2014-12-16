#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
int cal(long long a,long long n)
{
    long long p;
    if(n==1)
        return a%2006;
    p=cal(a,n/2);
    p*=p;
    if(n%2==1)
        p*=a;
    return p%2006;
}
int main()
{
	int x;
	while (1)
	{
		int t;
		cin>>x;
		if (x==0)
		break;	
		cout<<cal(x,x)<<endl;
	}
	system("pause");
}
