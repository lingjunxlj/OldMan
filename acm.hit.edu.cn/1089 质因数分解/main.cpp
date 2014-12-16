#include <iostream>
using namespace std;
int happy(int n)
{
	int r,f,t,d;
	f=t=d=1;
	for (r=0;r<=n;++r)
	{
		f=f*(r==n?2:4)%29;
		t=t*3%29;
		d=d*22%29;
	}
	r=(f-1)*(t-1)*(d-1)%29;
	return r*9%29;
}
int main()
{
	int n;
	while (cin>>n && n!=0)
	{
		cout<<happy(n%28)<<endl;
	}
	return 0;
}
