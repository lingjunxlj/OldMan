#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int in[50001];
int n;
int Lowbit(int t)
{
    return t & ( t ^ ( t - 1 ) );
}
int Sum(int end)
{
    int sum = 0;
    while(end > 0)
    {
        sum += in[end];
        end -= Lowbit(end);
    }
    return sum;
}
void Plus(int pos , int num)
{
    while(pos <= n)
    {
          in[pos] += num;
          pos += Lowbit(pos);
    }
}
int main()
{
    int t, x = 0;
    scanf("%d", &t);
    while (t--)
    {
        memset(in, 0, sizeof(in));
        x++;
        cin>>n;
        int temp;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &temp);
            Plus(i,temp);
        }

        int a, b;
        printf("Case %d:\n", x);
        in[0] = 0;
        string temp_string;
        while(cin>>temp_string)
        {
            if (temp_string == "End")
                break;


            if (temp_string == "Query")
            {
                cin>>a>>b;
                printf("%d\n", Sum(b) - Sum(a - 1));
            }
            if (temp_string == "Add")
            {
                cin>>a>>b;
                Plus(a, b);
            }
            if (temp_string == "Sub")
            {
                cin>>a>>b;
                Plus(a, (-1)*b);
            }
        }
    }
}
