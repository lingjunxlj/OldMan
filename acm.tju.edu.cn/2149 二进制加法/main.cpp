#include <iostream>
#include <string>
using namespace std;
int num[100];
int Add(string s)
{
	int i,l;
	l = s.length();
	for (i = 1; i <= l; i++)
	{
		if ( (s[l - i] == '0') || (s[l - i] == '1') )
        num[i] += s[l - i] - '0';
	}
	return 0;
}

int main()
{
	string a, b;
	int n, m, i;
	cin >>n;
	for (m = 1;m <= n; m++)
	{
		cin >>a>>b;
		memset(num, 0, sizeof(num));
		Add(a);
		Add(b);
		for (i = 1; i <= 90; i++)
		{
			num[i + 1] += num[i] / 2;
			num[i] %= 2;
		}
		i = 90;

		while ( (num[i] == 0) && (i > 1) )
		i--;
		printf("%d ", m);

		while (i > 1)
        printf("%d", num[i--]);

		printf("%d\n", num[1]);
	}
	return 0;
}
