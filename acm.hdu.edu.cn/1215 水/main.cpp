#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        int sum = 0, m = n;
        for (int i = 1; i < m; i++)
        {
            if (n % i == 0)
            {
                m = n / i;
                sum += i;
                if (n != m && i != m)
                sum += m;
            }
        }
        printf("%d\n", sum);
    }
}
