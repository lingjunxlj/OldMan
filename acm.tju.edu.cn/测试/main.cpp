#include <iostream>
#include <cstdio>
#include <map>

#include <cmath>
using namespace std;
const int MAXN = 1000000;
typedef long long LL;
int euler[1000000],p[1000000],res[1000000],num;
/*
void init() {
	num = 0;
	euler[1] = 1;
	for (int i = 2; i <= MAXN; i++) {
		if (!euler[i]) {
			euler[i] = i - 1;
			p[i] = i;
		}
		for (int j = 0; j < num && i * p[j] <= MAXN; j++) {
			if (i % p[j] == 0) {
				euler[i * p[j]] = euler[i] * p[j];
				break;
			} else {
				euler[i * p[j]] = euler[i] * (p[j] - 1);
			}
		}
	}
	for (int i = 1; i <= MAXN; i++) {
		LL t = (LL)i * euler[i];
		for (int j = i; j <= MAXN; j += i) {
			res[j] += t;
		}
	}
}
*/

map <int,int> memphi;

int phi(int rn)
{
	if (memphi.count(rn)) return memphi[rn];
	int n = rn;
	if (n == 1)
	{
		return 1;
	}
	int i = 2, m = n, root = int (sqrt (double (m)));
	while (i <= root)
	{
		if (m % i == 0)
		{
			n -= (n / i);
			do    {
				m /= i;
			} while (m % i == 0);
			root = int (sqrt (double (m)));
		}
		i ++;
	}
	if (m != 1)
	{
		n -= (n / m);
	}
	return memphi[rn] = n;
}
int main()
{
    freopen("a.txt","w",stdout);

    for (int i = 1; i <= MAXN; i++)
    printf("%d  ",phi(i));
}
