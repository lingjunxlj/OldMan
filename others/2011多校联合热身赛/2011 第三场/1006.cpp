//Miller-Rabin素性测试、Pollard rho启发式分解
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define MAX (pow(2.0, 60))                               //标记最大值
#define C 240
#define TIME 12                                                 //Miller测试次数
using namespace std;

unsigned long long MIN;

unsigned long long gcd(unsigned long long a,unsigned long long b)                         //计算a和b的最大公约数

{
        if(b==0)
           return a;
        return gcd(b,a%b);
}


unsigned long long mod_mult(unsigned long long a, unsigned long long b, unsigned long long n)        //计算(a*b) mod n
{
    unsigned long long s = 0;
    a=a%n;
    while(b)
    {
        if(b & 1)
        {
            s += a;
            if(s >= n)
              s -= n;
        }
        a = a<<1;
        if(a >= n)
          a -= n;
        b = b >> 1;
    }

    return s;
}


unsigned long long mod_exp(unsigned long long a, unsigned long long b, unsigned long long n)           //计算(a^b) mod n
{
    unsigned long long d= 1;
    a=a%n;
    while(b>=1)
    {
        if(b&1)
            d=mod_mult(d,a,n);
        a =mod_mult(a, a, n);
        b = b>> 1;
    }
    return d;
}


bool Wintess(unsigned long long a, unsigned long long n)            //以a为基对n进行Miller测试并实现二次探测
{
    unsigned long long m,x,y;
    int i,j=0;
    m=n-1;
    while(m%2==0)                                 //计算(n-1)=m*(2^j)中的j和m,j=0时m=n-1,不断的除以2直至n为奇数
    {
       m=m>>1;
       j++;
    }
    x= mod_exp(a,m,n);
    for(i= 1;i<=j;i++)
    {
        y= mod_exp(x,2,n);
        if((y==1)&&(x!=1)&&(x!= n - 1))     //二次探测
            return true;                              //返回true时,n是合数

        x=y;
    }
    if(y!= 1)
        return true;
    return false;
}


bool miller_rabin(int times,unsigned long long n)    //对n进行s次的Miller测试
{
    unsigned long long a;
    int i;
    if(n==1)
      return false;
    if(n==2)
      return true;
    if(n%2==0)
      return false;
    srand(time(NULL));
    for(i=1;i<=times;i++)
    {
        a = rand() % (n - 1) + 1;
        if(Wintess(a, n))
          return false;
    }
    return true;
}


unsigned long long Pollard(unsigned long long n,int c)     //对n进行因字分解,找出n的一个因子,注意该因子不一定是最小的
{
        unsigned long long i,k,x,y,d;
        srand(time(NULL));
        i=1;
        k=2;
        x=rand()%n;
        y=x;
        while(true)
        {
                   i++;
                   x=(mod_mult(x,x,n)+c)%n;
                   d=gcd(y-x,n);
                   if(d>1&&d<n)
                      return d;
                   if(y==x)                            //该数已经出现过,直接返回即可
                      return n;
                   if(i==k)
                   {
                           y=x;
                           k=k<<1;
                   }
        }
}
int num;
void get_small(unsigned long long n,int c)          //找出最小的素数因子
{
     unsigned long long m;
     if(n==1)
       return;
     if(miller_rabin(TIME,n))             //判断是否为素数
     {
        if(n<MIN)
            MIN=n;
        num++;
        //printf("%I64d\n", n);
        if (num > 2)
            return;
        return;
     }
     m=n;
     while(m==n)                             //找出n的一个因子
        m=Pollard(n,c--);
     get_small(m,c);                       //二分查找
     get_small(n/m,c);
}


int main()
{

    unsigned long long n;
    while(scanf("%I64d",&n) != EOF)
    {

        if (n & (n - 1) == 0)
        {
            printf("is not a D_num\n");
            continue;
        }
        num = 0;
        MIN=MAX;
        if(miller_rabin(TIME,n))
            printf("is not a D_num\n");
        else
        {
            get_small(n,C);
            //printf("%I64d\n", MIN);
            //printf("%d\n", num);
            if (num != 2)
            {
                if (MIN*MIN*MIN == n)
                    printf("%I64d %I64d %I64d\n", MIN, n/MIN, n);
                else
                    printf("is not a D_num\n");
               // printf("%d\n", num);
            }

            else
            {
                unsigned long long Next = n/MIN;
                if (Next == MIN)
                    printf("is not a D_num\n");
                else
                {
                    //printf("%d\n", miller_rabin(TIME,Next));
                    int fg = 0;

                    if (miller_rabin(TIME,Next))
                        printf("%I64d %I64d %I64d\n", MIN, Next, n);
                    else
                        printf("is not a D_num\n");
                }
            }

        }
    }
    return 0;
}
