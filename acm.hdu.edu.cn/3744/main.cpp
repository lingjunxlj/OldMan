#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
struct node
{
    int X;
    int R;
}rank[101];

bool cmp(const node a, const node b)
{
    return a.R < b.R;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m, fg = 0;
        cin>>n>>m;
        for (int i = 0; i < n; i++)
            cin>>rank[i].X>>rank[i].R;
        sort(rank, rank + n, cmp);
        int sum = 0, ans = 0;
        for (int i = 1; i < n; i++)
        {
            if (rank[i].X > rank[i - 1].X)
            {
                sum ++;
                ans = rank[i].X + 400 * sum;
                //cout<<"sum   "<<sum<<endl;
                if (ans > m)
                {
                    fg = 1;
                    break;
                }
            }
        }
        if (fg)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
}
