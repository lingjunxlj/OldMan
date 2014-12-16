/*
Miller Robin素性测试 + Pollard rho寻找素因子
Miller Robin 和 Pollard rho的理论想非常强，细节这里就不说了，可以参考
算法导论第31章
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#define MAX_L 64               //最长位数
#define TIMES 8                //miller robin素性测试的测试次数
#define MAX_VAL (pow(2.0, 60)) //定义最大值
#define CVAL 200
using namespace std;

//最小的素因子
long long minFactor;

//(1)计算a * b mod n, 思路: 利用b的二进制表示进行拆分计算
//(2)例如: b = 1011101那么a * b mod n = (a * 1000000 mod n + a * 10000 mod n + a * 1000 mod n + a * 100 mod n + a * 1 mod n) mod n
//(3)思路就是上面描述的那样, 那么可以用从低位往高位遍历b, 并用a来记录当前位为1的值，每次遇到b当前位为
//1就将结果值加上a并 mod n，然后a 要乘以2
long long multAndMod(long long a, long long b, long long n)
{
	a = a % n;
	long long res = 0;

	while(b)
	{
		//当前位为1
		if(b & 1)
		{
			//加上当前权位值
			res += a;
			//相当于mod n
			if(res >= n) res -= n;
		}
		//乘以2，提高一位
		a = a<<1;
		//mod n
		if(a >= n) a -= n;
		b = b >> 1;
	}

	return res;
}

//(1)计算a ^ b mod n, 思路: 和上面类似，也是利用b的二进制表示进行拆分计算
//(2)例如: b = 1011101那么a ^ b mod n = [(a ^ 1000000 mod n) * (a ^ 10000 mod n) * (a ^ 1000 mod n) * (a ^ 100 mod n) * (a ^ 1 mod n)] mod n
//(3)思路就是上面描述的那样, 那么可以用从低位往高位遍历b, 并用a来记录当前位为1的值，每次遇到b当前位为
//1就将结果乘上a并 mod n，然后a 要乘以a以提升一位
long long modAndExp(long long a, long long b, long long n)
{
	a = a % n;
	long long res = 1;
	while(b >= 1)
	{
		//遇到当前位为1，则让res * 当前a并mod n
		if(b & 1)
			res = multAndMod(res, a, n);
		//a * a以提升一位
		a = multAndMod(a, a, n);
		b = b >> 1;
	}
	return res;
}

//MillerRobin素性测试，true:素数，flase:合数
bool millerRobin(long long a, long long n)
{
	long long u = 0, cur = n - 1;
	int t = 0;
	bool find1 = false;
	while(cur != 0)
	{
		if(!find1)
		{
			int pb = cur % 2;
			if(pb == 0) t++;
			else find1 = true;
		}
		if(find1)
			break;
		cur = cur / 2;
	}
	u = cur;

	cur = modAndExp(a, u, n);
	long long now;
	for(int p = 1; p <= t; p++)
	{
		now = modAndExp(cur, 2, n);
		if(cur != 1 && now == 1 && cur != n - 1)
		{
			//printf("%d %d/n", cur, now);
			return false;
		}
		cur = now;
	}
	if(cur != 1)
	{
		//printf("a:%I64d u:%I64d n:%I64d val:%I64d/n", a, u, n, start);
		return false;
	}
	//printf("a:%I64d u:%I64d n:%I64d val:%I64d/n", a, u, n, start);
	return true;
}

//利用Miller Robin对n进行n次素性测试
bool testPrime(int times, long long n)
{
	if(n == 2) return true;
	if(n % 2 == 0) return false;

	long long a; int t;
	srand(time(NULL));
	for(t = 1; t <= times; t++)
	{
		a = rand() % (n - 1) + 1;
		if(!millerRobin(a, n)) return false;
	}
	return true;
}

long long gcd(long long a, long long b)
{
	if(b == 0) return (a);
	return gcd(b, a % b);
}

long long PollardRho(long long n, int c)
{
	int i = 1;
	srand(time(NULL));
	long long x = rand() % n;
	long long y = x;
	int k = 2;
	while(true)
	{
		i = i + 1;
		x = (modAndExp(x, 2, n) + c) % n;
		long long d = gcd(y - x, n);
		if(1 < d && d < n) return d;
		if(y == x) return n; //重复了, 说明当前x下无解，需要重新启动PollardRho
		if(i == k)
		{
			y = x;
			k = k * 2;
		}
	}
}

void getSmallest(long long n, int c)
{
	if(n == 1) return;
	//判断当前因子是否为素数
	if(testPrime(TIMES, n))
	{
		if(n < minFactor) minFactor = n;
		return;
	}
	long long val = n;
	//循环，知道找到一个因子
	while(val == n)
		val = PollardRho(n, c--);
	//二分
	getSmallest(val, c);
	getSmallest(n / val, c);
}
int main()
{
	long long n;
	while(scanf("%lld", &n) != EOF)
	{

		if (n == 1)
		{
		    printf("is not a D_num\n");
		    continue;
		}

		minFactor = MAX_VAL;
		if(testPrime(TIMES, n))
            printf("is not a D_num\n");
		else
		{
			getSmallest(n, CVAL);
            printf("%lld\n", minFactor);
            printf("%lld\n", n);
			long long Next_prime;
			//if (n%minFactor == 0)
			{
			    Next_prime = n/minFactor;
			    printf("%lld\n", Next_prime);

			    if (Next_prime != minFactor )
			    {
			        if (testPrime(TIMES, Next_prime))
                        printf("%lld %lld %lld\n", minFactor, Next_prime, n);
                    else
                        printf("is not a D_num\n");
			    }
                else
                    printf("is not a D_num\n");
			}
			//else
               // printf("is not a D_num\n");
		}
	}
	return 0;
}
