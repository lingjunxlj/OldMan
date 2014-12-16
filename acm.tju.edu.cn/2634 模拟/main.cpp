#include<iostream>
#include<string>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	char a[10], b[10], res[8];
	int n, i, la, lb, x1, x2, x3, x4, y1, y2, y3, y4, z1, z2, z3, z4, p1, p2, p3, p4;
	cin>>n;
	while(n--)
	{
		x1 = x2 = x3 = x4 = y1 = y2 = y3 = y4 = 0;
		scanf("%s %s", a, b);
		la = strlen(a);
		lb = strlen(b);
		for(i = 0; i < la; i++)
		{
			if(a[i] == 'm')
			{
				if(i == 0)
					x1 = 1;
				else
					x1 = a[i - 1] - 48;
			}
			if(a[i] == 'c')
			{
				if(i == 0 || a[i-1] == 'm')
					x2 = 1;
				else
					x2 = a[i - 1] - 48;
			}
			if(a[i] == 'x')
			{
				if(i == 0 || a[i-1] == 'm' || a[i-1] == 'c')
					x3 = 1;
				else
					x3 = a[i - 1] - 48;
			}
			if(a[i] == 'i')
			{
				if(i == 0 || a[i - 1] == 'm' || a[i - 1] == 'c' || a[i - 1] == 'x')
					x4 = 1;
				else
					x4 = a[i - 1] - 48;
			}
		}

		for(i = 0; i < lb; i++)
		{
			if(b[i] == 'm')
			{
				if(i == 0)
					y1 = 1;
				else
					y1 = b[i - 1] - 48;
			}
			if(b[i] == 'c')
			{
				if(i == 0 || b[i - 1] == 'm')
					y2 = 1;
				else
					y2 = b[i - 1] - 48;
			}
			if(b[i] == 'x')
			{
				if(i == 0 || b[i - 1] == 'm' || b[i - 1] == 'c')
					y3 = 1;
				else
					y3 = b[i - 1] - 48;
			}
			if(b[i] == 'i')
			{
				if(i == 0 || b[i - 1] == 'm' || b[i - 1] == 'c' || b[i - 1] == 'x')
					y4 = 1;
				else
					y4 = b[i - 1] - 48;
			}
		}

		z4 = x4 + y4;
		z3 = x3 + y3;
		z2 = x2 + y2;
		z1 = x1 + y1;
		if(z4 == 0 || z4 == 10)
			p4 = 0;
		else if(z4 > 10)
			p4 = z4 - 10;
		else
			p4 = z4;
		if(z4 >= 10)
			z3 = z3 + 1;
		if(z3 == 0 || z3 == 10)
			p3 = 0;
		else if(z3 > 10)
			p3 = z3 - 10;
		else
			p3 = z3;
		if(z3 >= 10)
			z2 = z2 + 1;
		if(z2 == 0 || z2 == 10)
			p2 = 0;
		else if(z2 > 10)
			p2 = z2 - 10;
		else
			p2 = z2;
		if(z2 >= 10)
			z1 = z1 + 1;
		p1 = z1;

		res[0] = p1 + 48;
		res[1] = 'm';
		res[2] = p2 + 48;
		res[3] = 'c';
		res[4] = p3 + 48;
		res[5] = 'x';
		res[6] = p4 + 48;
		res[7] = 'i';
		for(i = 0; i < 7; i += 2)
		{
			if((res[i] - 48) != 0 && (res[i] - 48) != 1)
				cout<<res[i]<<res[i + 1];
			if((res[i] - 48) == 1)
				cout<<res[i + 1];
		}
		cout<<endl;
	}
}
