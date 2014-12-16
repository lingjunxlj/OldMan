#include <string>
#include <cstdio>
int f[26],t[25],d[26],l[26],Time[26][26],ft[26];
int n,h;
int total[26];
int work()
{
    int i, j, k, temp, max=0, tt;
    for(i = 1; i<= n; i++)
    {
        for(k = 1; k <= i; k++)
        {
            ft[k] = f[k];
        }
        tt = (h-l[i])/5;
        for(j = 1;j <= tt; j++)
        {
            temp=0;
            for(k = 1;k <= i; k++)
            if(ft[temp] < ft[k])
            {
                temp = k;
            }
            if(ft[temp]==0)
            {
                Time[i][1]+= 5;
            }
            else
            {
                Time[i][temp]+= 5;
                total[i]+= ft[temp];
                ft[temp]-= d[temp];

                if(ft[temp] < 0)
                {
                    ft[temp] = 0;
                }
            }
        }
    }

    for(i = 1;i <= n;i++)
    {
        if(total[i] > max)
        {
            max = total[i];
            j = i;
        }
    }

    if(max==0)
    {
        j = 1;
    }
    Time[1][1] = h;
    return j;
}
int main()
{
    int i;
    scanf("%d", &n);
    while(1)
    {
        memset(f, -1, sizeof(f));
        memset(t, 0, sizeof(t));
        memset(d, 0, sizeof(d));
        memset(l, 0, sizeof(l));
        memset(Time, 0, sizeof(Time));
        memset(total, 0, sizeof(total));
        scanf("%d", &h);
        h = h*60;
        for (i = 1;i <= n; i++)
        {
            scanf("%d", &f[i]);
        }
        for (i = 1;i <= n; i++)
        {
            scanf("%d", &d[i]);
        }
        for (i = 2;i <= n;i++)
        {
            scanf("%d", &t[i]);
            l[i] = l[i-1] + 5*t[i];
        }
        int ans;
        ans = work();
        for (i=1;i<n;i++)
        {
            printf("%d, ",Time[ans][i]);
        }
        printf("%d\n",Time[ans][n]);
        printf("Number of fish expected: %d\n",total[ans]);
        scanf("%d", &n);
        if (n==0)
        break;
        else
        printf("\n");
    }
}


