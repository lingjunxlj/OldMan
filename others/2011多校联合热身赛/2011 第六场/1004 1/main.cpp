#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>

using namespace std;
#define N 30
int n;
bool vis[N];

int main()
{
    int i,j,k,cnt;
    double ans = 0;
    while(scanf("%d",&n),n!=-1)
    {
        if(n == 0) {printf("0\n"); continue;}
        ans = pow(6.0,n);
        for(i = 1; i < n; i++)
        {
            memset(vis,0,sizeof(vis)); cnt = 0;
            for(j = 0; j < n; j++)
                if(!vis[j])
                {
                    cnt++; k = j;
                    while(!vis[k])
                    {
                        vis[k] = true;
                        k = (k+i)%n;
                    }
                }
            ans += pow(6.0,cnt);
        }
        if(n%2 == 1) ans += n*pow(6.0,(n+1)/2);
        else ans += (n/2)*(pow(6.0,n/2)+pow(6.0,n/2+1));
        ans = ans / (2*n);
        printf("%.0f\n",ans);
    }
    return 0;
}
