#include <cstdio>
#include <cmath>
int main ()
{
	 int n,m,y;
	 while (scanf("%d %d %d",&n,&m,&y))
	 {
	     if (n==0&&m==0&&y==0)
	     break;
         int i=1,q,sum=0;
         {
            while(i<=n)
            {
                q=i*i;
                if(q>=m&&q<=y)
                sum++;
                i++;
            }
            printf ("%d\n",sum);
        }
	 }
}
