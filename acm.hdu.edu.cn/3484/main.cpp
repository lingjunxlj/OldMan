#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 101;
int main()
{
    int a[N],b[N],m,n;
    while(scanf("%d %d", &m, &n) && (m!=-1 && n!=-1))
    {
        int temp;
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                scanf("%d", &temp);
                if(temp)
                    a[i]++;
            }
        }
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                scanf("%d", &temp);
                if(temp)
                    b[i]++;
            }
        }
        for(int i = 0; i < m; i++)
        {
            if(a[i]!=b[i] && a[i]!=(n-b[i]))
                break;
        }
        puts(i==m?"Yes":"No");
    }
    return 0;
}
