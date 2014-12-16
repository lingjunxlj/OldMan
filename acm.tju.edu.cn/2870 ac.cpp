#include<stdio.h>
#include<string.h>
int data[300][300],aa,bb,cc,a[300],b[300],n,m,i,j,k,t;
int main()
{
    while(1)
   {
     scanf("%d",&n);
    if(n==0)break;
  scanf("%d",&m);
    memset(data,3,sizeof(data));
    for(i=0;i<m;i++)
   {
        scanf("%d%d%d",&aa,&bb,&cc);
        data[aa][bb]=cc;
        data[bb][aa]=cc;
   }
    for(i=0;i<n;i++)data[i][i]=0;
   for(k=0;k<n;k++)
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(data[i][k]+data[k][j]<data[i][j])
                    data[i][j]=data[i][k]+data[k][j];
   for(i=0;i<n;i++)a[i]=data[0][i];
    for(i=0;i<n;i++)b[i]=i;
    for(i=0;i<n;i++)
        for(j=0;j<n-1;j++)
            if((a[j]>a[j+1]) || ((a[j]==a[j+1])&& b[j]>b[j+1]))
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
                t=b[j];
                b[j]=b[j+1];
               b[j+1]=t;
            }

    scanf("%d",&k);
   printf("%d\n",b[k]);
    }
   return 0;
}
