#include <cstdio>
#include <string>
int C(int n, int r)
{
	int i, j, s = 1;
	if(n - r > r) r = n - r;
	for(i = 0, j = 1; i < r; i++)
		for(s *= n - i; j <= r && !(s % j); j++) s /= j;
	return s;
}
int main()
{
    char a[10];
    while (scanf("%s",a)!=EOF)
    {
        int i,len=strlen(a),flag=1;
        for (i=1;i<len;i++)
        if ((a[i]-a[0])<=0)
        flag=0;
        if (flag)
        {
            int sum=0;
            for (i=1;i<=len;i++)
            sum+=C(26,i);
            for (i=0;i<len;i++)
            sum-=C(122-a[i],len-i);
            printf("%d\n",sum);
        }
        else
        printf("0\n");
    }
}
