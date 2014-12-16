#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, mid;
int sum, temp;
void BS(int st, int end, int num)
{
    mid = (st + end) / 2;
    if (num > mid)
    {
        temp++;
        BS(mid + 1, end, num);
    }
    else if (num < mid)
    {
        temp++;
        BS(st, mid - 1, num);
    }
    else
    {
        temp++;
        return;
    }
}
int main()
{
    while(scanf("%d", &n) != EOF)
    {
        sum = 0;
        for (int i = 1 ; i <= n; i++)
        {
            temp = 0;
            BS(1, n, i);
            //cout<<"temp  "<<temp<<endl;
            sum += temp;
        }
        printf("%.2lf\n", (double)sum/n);

    }
}
