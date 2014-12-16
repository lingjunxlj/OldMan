#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int dp[1<<19];
int dfs(int m);
void print(int m);
void cal(int &, int);
int main()
{
       memset(dp, -1, sizeof(dp));
       dp[1] = dp[2] = 1;
       dp[0] = dp[3] = 0;
       int Scen, S, t, n, m;
       cin>>Scen;
       for(S = 1; S <= Scen; S++)
       {
            m = 0;
            cin>>n;
            while(n--)
            {
                cin>>t;
                m += ( 1 << (t - 2) );
            }
            cout<<"Scenario #"<<S<<":\n";
            if( dfs(m) )print(m);
            else cout<<"There is no winning move.\n\n";
       }
       return 0;
}

int dfs(int m)
{
    if(dp[m] != -1)return dp[m];
    int t, n;
    for(int i = 2; i <= 20; i++)
    {
        n = m;
        t = (1 << (i - 2) );
        if(n & t)
        {
            cal(n, i);
            if(dfs(n))continue;
            else
            {
                dp[m] = 1;
                return 1;
            }
        }
    }
    dp[m] = 0;
    return 0;
}
void print(int m)
{
    cout<<"The winning moves are:";
    int t, n;
    for(int i = 2; i <= 20; i++)
    {
        t = (1 << (i - 2));
        n = m;
        if(n & t)
        {
            cal(n, i);
            if(dfs(n))continue;
            cout<<' '<<i;
        }
    }
    cout<<'.'<<endl<<endl;
}
void cal(int & m, int k)
{
    int t = (1 << (k - 2));
    m &= ~t;
    for(int i = 2; i <= 20; i++)
    {
        t = (1 << (i - 2));
        if((m & t) == 0)
        {
            for(int j = k; j + i <= 20; j += k)
            {
                int n = (1 << (i + j - 2));
                if(m & n)
                m &= ~(1 << (i + j - 2));
            }
        }
    }
}
