#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
long long temp_1, temp_2;
char sock[10];
int main()
{
    int n;
    while(scanf("%ld", &n) != EOF)
    {
        getchar();
        gets(sock);
        temp_1 = 0;
        for(int i = 0; i <= 6; i++)
            temp_1 = temp_1 * 131 + sock[i];
        for(int i = 1; i < 2 * n - 1; i++)
        {
            gets(sock);
            temp_2 = 0;
            for(int j = 0; j <= 6; j++)
                temp_2 = temp_2 * 131 + sock[j];
            temp_1 = temp_1 ^ temp_2;
        }
        int k = 0;
        while(temp_1 > 0)
        {
            sock[k] = temp_1 % 131;
            k++;
            temp_1 /= 131;
        }
        for(int i = k - 1; i >= 0; i--)
            printf("%c", sock[i]);

        printf("\n");
    }
    return 0;
}
