#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n, m, i, s=0;
	scanf("%d%d", &n, &m);
	for (i=2; i<=n; i++) 
	s=(s+m)%i;
	printf ("%d\n", s+1);
	system("pause");
}
/*有问题请看http://ahauhs.blog.163.com/blog/static/298541892008772514702/?hasChannelAdminPriv=true*/ 
