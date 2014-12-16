#include <iostream>
using namespace std;
int f(int m,int n)
{ if(m<0)
   return 0;
  if(m==0||n==1)
   return 1;
  return f(m-n,n)+f(m,n-1);
}
int main()
{
	int x;
	cin>>x;
	while (x--)
	{
		int m,n;
		cin>>m>>n;
		cout<<f(m,n)<<endl;
	}
}
		
