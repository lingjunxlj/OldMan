#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>

const int M=1020;

using namespace std;

int main()
{
    int n,m;
    char tmp[M];
    int a[M];
    int b[M];

    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(a,0,sizeof(a));
        int res=0;
        for(int i=0; i<n; i++)
        {
            scanf("%s",tmp);
            for(int j=0; j<m; j++)
                if(tmp[j]=='1')
                    a[j]++;
                else
                    a[j]=0;
            for(int j=0; j<m; j++)
                b[j]=a[j];
            sort(b,b+m);
            int t=-1;
            for(int j=0; j<m; j++)
            {
                if(t!=b[j])
                {
                    t=b[j];
                    int sum=t*(m-j);
                    if(sum>res)
                        res=sum;
                }
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
