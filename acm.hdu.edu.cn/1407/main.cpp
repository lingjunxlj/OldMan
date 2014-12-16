#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n, x, y, z;
    while(scanf("%d", &n) != EOF)
    {
        for(x = 1; x <= 100; x++)
            for(y = 1; y <= 100; y++)
                for(z = 1; z <= 100;z++)
                {
                    if(x * x + y * y + z * z == n)
                    {

                        goto A;
                    }
                 }
        A:printf("%d %d %d\n", x, y, z);
    }
    return 0;
}
