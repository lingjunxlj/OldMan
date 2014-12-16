#include <stdio.h>
#include <string.h>
int Pow(long long a,long long b,int M){long long t=1;while(b){if(b&1) t=t*a%M;a=a*a%M;b>>=1;}return t;}
int main(){int n;while(scanf("%d",&n)!=EOF && n){int res=Pow(2,n-1,n);printf("%d\n", res+1);}}
