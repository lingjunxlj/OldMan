//Miller-Rabin���Բ��ԡ�Pollard rho����ʽ�ֽ�
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define MAX (pow(2.0, 60))                               //������ֵ
#define C 240
#define TIME 12                                                 //Miller���Դ���
using namespace std;

unsigned long long MIN;

unsigned long long gcd(unsigned long long a,unsigned long long b)                         //����a��b�����Լ��

{
        if(b==0)
           return a;
        return gcd(b,a%b);
}


unsigned long long mod_mult(unsigned long long a, unsigned long long b, unsigned long long n)        //����(a*b) mod n
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


unsigned long long mod_exp(unsigned long long a, unsigned long long b, unsigned long long n)           //����(a^b) mod n
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


bool Wintess(unsigned long long a, unsigned long long n)            //��aΪ����n����Miller���Բ�ʵ�ֶ���̽��
{
    unsigned long long m,x,y;
    int i,j=0;
    m=n-1;
    while(m%2==0)                                 //����(n-1)=m*(2^j)�е�j��m,j=0ʱm=n-1,���ϵĳ���2ֱ��nΪ����
    {
       m=m>>1;
       j++;
    }
    x= mod_exp(a,m,n);
    for(i= 1;i<=j;i++)
    {
        y= mod_exp(x,2,n);
        if((y==1)&&(x!=1)&&(x!= n - 1))     //����̽��
            return true;                              //����trueʱ,n�Ǻ���

        x=y;
    }
    if(y!= 1)
        return true;
    return false;
}


bool miller_rabin(int times,unsigned long long n)    //��n����s�ε�Miller����
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


unsigned long long Pollard(unsigned long long n,int c)     //��n�������ַֽ�,�ҳ�n��һ������,ע������Ӳ�һ������С��
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
                   if(y==x)                            //�����Ѿ����ֹ�,ֱ�ӷ��ؼ���
                      return n;
                   if(i==k)
                   {
                           y=x;
                           k=k<<1;
                   }
        }
}
int num;
void get_small(unsigned long long n,int c)          //�ҳ���С����������
{
     unsigned long long m;
     if(n==1)
       return;
     if(miller_rabin(TIME,n))             //�ж��Ƿ�Ϊ����
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
     while(m==n)                             //�ҳ�n��һ������
        m=Pollard(n,c--);
     get_small(m,c);                       //���ֲ���
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
