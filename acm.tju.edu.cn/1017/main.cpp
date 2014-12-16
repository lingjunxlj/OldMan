/*可取数字是否在集合中可用数字二进制第 I 位是否为1 来标志，可取数字 2、3、4、5、6、7、8、9、10、11、12、13、14、15、16、17、18、19、20一共有19个，故至少需要19个二进制位来表示也即数字（1 << 19）来表示。

例：若只剩 2 、3可以被取出来，则用二进制数 0000000000000000011 即十进制数 3 来表示。

       必败态（P）为首取者无论怎样取数字都不会胜利,必胜态（N）为首取者取剩下可取数字中某一个时可以到达必胜态的状态。状态 m ,只要有一种可能取子能达到必败态 P ＝》m 的状态为必胜态; 只有所有可能取子全部达到必胜态 N ＝》 m 的状态为必败态。

       开一个int dp[1<<19] 标志数组，dp[m] == 0 则为 m 态为必败态; dp[m] == 1 则 m 为必胜态; dp[m] == -1 是数组的初始状态。

       本题用 dfs() ＋ dp 做深搜即可。

*/

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
       dp[0] = dp[3] = 0;                              //inital
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
    {          //从 2 到 20 依次遍历
        n = m;
        t = (1 << (i - 2) );
        if(n & t)
        {                                          //找到一个可以取的数 i
            cal(n, i);                              //把 i 从集合 m 中取出来，得到的新状态放在集合 n 中
            if(dfs(n))continue;                //集合 n 为一个必胜态，则继续
            else
            {                                         // 集合 n 可以到达一个必败态，故 m 为必胜态
                dp[m] = 1;                           //cout<<i<<endl;
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
{                     //把可以取的数 k 从集合 m 中取出来后到达新状态 m
    int t = (1 << (k - 2));                   //先把 k 取出
    m &= ~t;
    for(int i = 2; i <= 20; i++)
    {
        t = (1 << (i - 2));
        if((m & t) == 0)
        {                 //找到一个已经被取出的数 i
            for(int j = k; j + i <= 20; j += k)
            { //这个 for 循环与下面作为注释的代码有异曲同工之妙
                int n = (1 << (i + j - 2));
                if(m & n)
                m &= ~(1 << (i + j - 2));
            }
            //如果 i + k 在集合 m 中，则就把它取出来吧
            /*int n = (1 << (i + k - 2));
            if((m & n) && (i + k <= 20))
            m &= ~n;*/
        }
    }
}
