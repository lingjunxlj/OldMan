#include<cstdio>
int a[18]=
{
    0,15,150,750,7500,75000,750000,7500000,75000000,750000000
};
int main()
{

    int i, j, k, m, n;
    int cas, key;

    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%d %d", &n, &m);
        key = m * a[n];

        if(n == 2)
        {
             if(m % 4 != 0)
                key += (m / 4) * a[n];
             else
                key += (m / 4 - 1) * a[n];
         }
         else
         {
             if(m % 9 != 0)
                key += (m / 9) * a[n];

             else
                key += (m / 9 - 1) * a[n];
         }
         printf("%d\n", key);
     }
}
