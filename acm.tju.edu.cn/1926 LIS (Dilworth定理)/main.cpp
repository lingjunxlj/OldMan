#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 900;
int k, a[MAX], tail[MAX], b[MAX];
void LIS()
{
    int i, j, m, n, len;
    int mid, left, right;

    n = 1;
    for(i = k - 1; i >= 1; i--)
    b[n++] = a[i];

    n--;

    len = 1;
    tail[1] = b[1];

    for(i = 2; i <= n; i++)
    {
        if(b[i] > tail[len])
        {
            len++;
            tail[len] = b[i];
        }
        else
        {
            left = 1;
            right = len;
            while(left < right)
            {
                mid = (left + right) / 2;

                if(tail[mid] < b[i])
                    left = mid + 1;
                else
                    right = mid;
            }
            tail[left] = b[i];
        }
    }
    printf("%d\n", len);
}
int main()
{
    int i, j, m, n;
    while(1)
    {
        k = 1;
        scanf("%d %d", &i, &j);

        if(i == -1 && j == -1)
        break;

        a[k++]=j;
        while(scanf("%d %d", &i, &j))
        {
            if(i == 0 && j == 0)
            {
                LIS();
                break;
            }
            a[k++] = j;
        }
    }
}
