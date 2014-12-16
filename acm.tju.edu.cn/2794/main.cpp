#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int MAx = 1100001;
int a[MAx][2], t, n;
int main()
{
    int i,j;
    cin>>t;
    while(t--)
    {
        scanf("%d", &n);
        for(i = 1; i <= 2; i++)
            for(j = 1; j <= n; j++)
                cin>>a[j][i];

        for(j = n - 1; j >= 1; j--)
        {
            for(i = 2; i >= 1; i--)
            {
                if(i == 2)
                    a[j][2] = max(a[j+1][1], a[j+1][2] + a[j][2]);
                if(i == 1)
                    a[j][1] = max(a[j+1][2], a[j+1][1] + a[j][1]);
            }
        }
        int MAX = -1;
        if(a[1][1] > MAX)
            MAX = a[1][1];
        if(a[1][2] > MAX)
            MAX = a[1][2];
        printf("%d\n", MAX);
    }
}
