#include <cstdio>
#include <cstring>
const int N = 20000 ;
bool prime[N];
int cnt = 0, list[N];
int main()
{
    int n;
    memset(prime,0,sizeof(prime));
    int i, j ;
    for(i = 2; i*i < N; i++)
    {
        if(prime[i])
            continue;
        for(j = i; i*j < N; j++)
            prime[i*j] = 1;
    }
    list[cnt++] = 1 ;
    for(i = 2; i < N; i++)
        if(!prime[i])
            list[cnt++] = i ;
    while(scanf("%d",&n) != EOF)
    {
        int max = 0, f, t;
        for(i = 0 ; i < n ; i++)
        {
            scanf("%d", &t);
            for(j = 0 ; list[j] <= t ;j++)
                if(t%list[j] == 0)
                    if(max < list[j])
                    {
                        max = list[j] ;
                        f = t ;
                    }
        }
        printf("%d\n",f);
    }
    return 0;
}
