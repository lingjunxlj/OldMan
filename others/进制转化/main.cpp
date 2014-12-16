#include <iostream>
#include <cstdio>
using namespace std;
void two(int n,int t)
{
    int x = n;
    int num[100];
    int m = 0;
    while (x)
    {
        num[m++] = x%t;
        x /= t;
    }
    for (int i = m-1; i >= 0; i--)
        printf("%d",num[i]);
    printf("\n");
}
int main()
{
    int n;
    while (cin>>n)
    {
        int t;
        //cin>>t;
        two(n, 2);
        two(n, 8);
        two(n, 4);
        two(n, 16);
    }
}
