#include <iostream>
#include <cstdlib>
#include <cstdlib>
using namespace std;
int main()
{
	double x,y,z;
	while (cin>>x>>y>>z&&x!=0&&y!=0&&z!=0)
	{
		printf ("%.2lf\n",z*z/2/9.8-9.8*y*y/2/z/z+x);
	}
	system("pause");
}
