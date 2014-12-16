#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
using namespace std;
int main()
{
    map<string,int> hash;

    int n, m;
    while (scanf("%d %d", &n, &m), n||m)
    {
        int i,j,k;

        char str[101];
        int res[20001];
        hash.clear();
        for( i = 0 ; i < n ; i++ )
        {
            scanf("%s",str);
            string tmp = str;
            hash[tmp]++;
        }
        memset(res, 0, sizeof(res));

        map<string,int>::iterator p;
        for( p = hash.begin(); p != hash.end(); p++ )
            res[p->second]++;

        for( i = 1; i <= n; i++ )
            printf("%d\n", res[i]);

    }
    return 0;
}

