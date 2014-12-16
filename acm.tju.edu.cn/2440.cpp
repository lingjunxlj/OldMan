#include <iostream>
#include <cstdlib>
using namespace std;
int t[101];
int f ( int n)
{
	int res=0;
	if(n == 1) return t[0];
    if(n == 2) return t[1]; 
    if(n == 3) return t[0] + t[1] + t[2];
    if(2 * t[1] > t[0] + t[n-2])
        res = t[0] + t[0] + t[n-2] + t[n-1];
    else res = t[0] + t[1] + t[1] + t[n-1];
    res += f(n - 2);
    return res;
}
int main()
{
	int n,i;
	cin>>n;
	for (i=0;i<n;i++)
	cin>>t[i];
	cout<<f(n)<<endl;
	system("pause");
}
