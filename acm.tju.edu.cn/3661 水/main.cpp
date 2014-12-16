#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int A[1001], B[1001], n, t;
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    while (scanf("%d%d", &n, &t) != EOF)
    {
        for (int i = 0; i < n; i++)
            scanf("%d", &A[i]);
        for (int j = 0; j < n; j++)
            scanf("%d", &B[j]);
        sort(A, A + n);
        sort(B, B + n, cmp);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (A[i] + B[i] > t)
            sum += A[i] + B[i] - t;
        }
        printf("%d\n", sum);
    }
}
