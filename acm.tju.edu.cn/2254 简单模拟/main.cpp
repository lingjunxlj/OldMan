#include <cstdio>
#include <string>
int num[26][2];
int main()
{
    int t;
    scanf("%d",&t);
    if (t==0)
    return 0;
    while (t--)
    {
        memset(num,0,sizeof(num));
        int n;
        int i,j,count;
        scanf("%d",&n);
        int min=0,max=99999;
        for (i=0;i<n;i++)
        {
            char x;
            getchar();
            scanf("%c %d %d",&x,&num[i][0],&num[i][1]);
            if(max<num[i][1])
            max=num[i][1];
			if(min>num[i][0])
            min=num[i][0];
		}
		for(i=min;i<max;i++)
		{
			count=0;
			for(j=0;j<n;j++)
            if(i >= num[j][0] && i < num[j][1])
            count++;
			if(count)
            printf("%c",'A'+count-1);

		}
		printf("\n");
	}
	return 0;
}




