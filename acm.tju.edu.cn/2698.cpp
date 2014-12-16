#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int f[50000]={0};
int a[20000]={0};

//----------------------------------can数组保存的是 i 是否为素数

int c[50001]={0};
int main()
{
 c[1]=1;
 for (int i=2;i*i<=40000;i++)
  for (int j=2;j*i<=40000;j++)
   c[i*j]=1;

//------------------------------把相应的素数找出来，存到a数组里,同时记录个数 ji
 int ji;
 ji=0;
 for (int i=2;i<=40000;i++)
  if (c[i]==0)
  {
   ji+=1;
   a[ji]=i;
   }

//----------------------------------枚举每两个素数相加的结果
 for (int i=1;i<=ji;i++)
  for (int j=i;j<=ji;j++)
  if (a[i]+a[j]<=40000)
  f[a[i]+a[j]]+=1;

//----------------------------------读入，既输出。
 int n;
 while (scanf("%d",&n)&&n!=0)
  printf("%d\n",f[n]);
 system("pause");
}
