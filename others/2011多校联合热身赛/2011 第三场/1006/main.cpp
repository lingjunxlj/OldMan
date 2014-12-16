/*
Miller Robin���Բ��� + Pollard rhoѰ��������
Miller Robin �� Pollard rho��������ǳ�ǿ��ϸ������Ͳ�˵�ˣ����Բο�
�㷨���۵�31��
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#define MAX_L 64               //�λ��
#define TIMES 8                //miller robin���Բ��ԵĲ��Դ���
#define MAX_VAL (pow(2.0, 60)) //�������ֵ
#define CVAL 200
using namespace std;

//��С��������
long long minFactor;

//(1)����a * b mod n, ˼·: ����b�Ķ����Ʊ�ʾ���в�ּ���
//(2)����: b = 1011101��ôa * b mod n = (a * 1000000 mod n + a * 10000 mod n + a * 1000 mod n + a * 100 mod n + a * 1 mod n) mod n
//(3)˼·������������������, ��ô�����ôӵ�λ����λ����b, ����a����¼��ǰλΪ1��ֵ��ÿ������b��ǰλΪ
//1�ͽ����ֵ����a�� mod n��Ȼ��a Ҫ����2
long long multAndMod(long long a, long long b, long long n)
{
	a = a % n;
	long long res = 0;

	while(b)
	{
		//��ǰλΪ1
		if(b & 1)
		{
			//���ϵ�ǰȨλֵ
			res += a;
			//�൱��mod n
			if(res >= n) res -= n;
		}
		//����2�����һλ
		a = a<<1;
		//mod n
		if(a >= n) a -= n;
		b = b >> 1;
	}

	return res;
}

//(1)����a ^ b mod n, ˼·: ���������ƣ�Ҳ������b�Ķ����Ʊ�ʾ���в�ּ���
//(2)����: b = 1011101��ôa ^ b mod n = [(a ^ 1000000 mod n) * (a ^ 10000 mod n) * (a ^ 1000 mod n) * (a ^ 100 mod n) * (a ^ 1 mod n)] mod n
//(3)˼·������������������, ��ô�����ôӵ�λ����λ����b, ����a����¼��ǰλΪ1��ֵ��ÿ������b��ǰλΪ
//1�ͽ��������a�� mod n��Ȼ��a Ҫ����a������һλ
long long modAndExp(long long a, long long b, long long n)
{
	a = a % n;
	long long res = 1;
	while(b >= 1)
	{
		//������ǰλΪ1������res * ��ǰa��mod n
		if(b & 1)
			res = multAndMod(res, a, n);
		//a * a������һλ
		a = multAndMod(a, a, n);
		b = b >> 1;
	}
	return res;
}

//MillerRobin���Բ��ԣ�true:������flase:����
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

//����Miller Robin��n����n�����Բ���
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
		if(y == x) return n; //�ظ���, ˵����ǰx���޽⣬��Ҫ��������PollardRho
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
	//�жϵ�ǰ�����Ƿ�Ϊ����
	if(testPrime(TIMES, n))
	{
		if(n < minFactor) minFactor = n;
		return;
	}
	long long val = n;
	//ѭ����֪���ҵ�һ������
	while(val == n)
		val = PollardRho(n, c--);
	//����
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
