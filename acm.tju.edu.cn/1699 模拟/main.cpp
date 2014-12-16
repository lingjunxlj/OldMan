#include <iostream>
using namespace std;

int main()
{
	int a, b, i, j, n, l, r;

	cin >> n;
	j=1;
	while(n--)
	{
		cin >> a >> b;
		l = r = 0;
		while(!(a==1 && b==1))
		{

			if(a>b)
			{
				l += (a/b);
				if(a%b==0)
				{
					l--;
				}
				a = (a % b);
				if(b == 1)
				{
					a = 1;
				}
			}
			else
			{
				r += (b/a);
				if(b % a==0)
				{
					r--;
				}
				b = (b % a);
				if(a == 1)
				{
					b = 1;
				}
			}
		}
		cout << "Scenario #" << j++ << ":" << endl;
		cout << l << " " << r << endl << endl;
	}

	return 0;
}
