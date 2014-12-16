#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int num[1000];
int sum;
int main()
{
    int t, x= 1;
    cin>>t;
    while(t--)
    {
        int n;

        sum = 0;
        cin>>n;
        memset(num, 0, sizeof(num));
        for (int i = 0; i < n; i++)
        {
            cin>>num[i];
            sum += num[i];
        }

        printf("Case %d: %.6lf\n",x++, (double)num[0]/(sum * 1.0));
    }
}
