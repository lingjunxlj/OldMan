#include<cstdio>
#include<cstdlib>
#include<math.h>

int main()
{
    double price[100][100];
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            scanf("%lf",&price[i][j]);
        }
    }
    int n;
    int pos[11];
    double harga;
    double res = 0.00;
    double temp;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)break;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&pos[i]);
        }
        scanf("%lf",&harga);
        //harga=int(harga*100)/100;
        temp=harga;
        harga = price[0][pos[0]-1]*harga;
        for(int i=1;i<n;i++)
        {
            harga = price[pos[i-1]-1][pos[i]-1]*harga;
        }
        harga = harga*price[pos[n-1]-1][0];
        res=harga*100;
        temp=floor(res);
        temp=res-temp;
        if(temp >= 0.5)harga+=0.01;
        if(harga < 1)
        {
            printf("%.0lf\n",harga);
        }
        else
        {
            printf("%.2lf\n",harga);
        }
    }
    return 0;
}
