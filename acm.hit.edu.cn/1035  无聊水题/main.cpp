#include <stdio.h>
#include <string.h>
const short p2[8] = {1,2,4,8,16,32,64,128};
char buf[128];
short n,m;
int main(){char dummy[130];char flag;short p,cnt=0;short i,k;while(1){scanf("%d",&n);if(n==0) break;getchar();gets(dummy);
gets(buf);scanf("%d\n",&m);printf("S-Tree #%d:\n",++cnt);for(k=0;k<m;k++){p = (p2[n]-1)/2;for(i=n-1;i>=1;i--)
{flag = getchar();if(flag=='0') p -= p2[i-1];else if(flag=='1') p += p2[i-1];}flag = getchar();
if(flag=='1') p++;getchar();putchar(buf[p]);}printf("\n\n");}}
