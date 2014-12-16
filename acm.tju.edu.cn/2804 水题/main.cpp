#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    char ch[2000];
    int i ,k, a[1010], m, n;
    while(cin>>ch)
    {
        n = strlen(ch);
        k = 0;

        if(n == 1 && ch[0] < '3')
        {
            printf("0\n");
            continue;
        }
        for(i = 0; i < n; i++)
        {
            m = 10 * k + ch[i] - 48;
            a[i] = m / 3;
            k = m % 3;
        }
        if(a[0])
        cout<<a[0];

        for(i = 1;i < n;i++)
        printf("%d", a[i]);

        printf("\n");
    }
}
