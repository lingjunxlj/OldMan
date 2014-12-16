#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<functional>
#include<climits>
using namespace std;

const int Max = 2;
struct Mat
{
    int matrix[Max][Max];
}e,init;

int mod, temp;
int map[300][300];
int source;
int sink;

const static int N = 405;

int mat[N][N];  //残留网络，初始为原图
int d[N];       //标号
int num[N];     //num[i]表示标号为i的顶点数有多少
bool vst[N];
int pre[N];
int n, m;

Mat operator *(Mat a,Mat b)
{
    Mat c;
    int i, j, k;
    for(i=0; i<Max; i++)
    {
        for(j=0; j<Max; j++)
        {
            c.matrix[i][j] = 0;
            for(k=0; k<Max; k++)
            {
                c.matrix[i][j] += a.matrix[i][k]*b.matrix[k][j];
                c.matrix[i][j] %= mod;
            }
        }
    }
    return c;
}

Mat operator +(Mat a, Mat b)
{
    Mat c;
    int i, j;
    for(i=0; i<Max; i++)
    {
        for(j=0; j<Max; j++)
            c.matrix[i][j] = (a.matrix[i][j] + b.matrix[i][j])%mod;
    }
    return c;
}

Mat operator ^(Mat a, int x)
{
    Mat p = e, q = a;
    while(x)
    {
        if(x&1)
          p = p*q;
        x >>=1;
        q = q*q;
    }
    return p;
}

Mat solve(Mat a, int x)
{
    if(x==1)
        return a;
    else if(x&1)
        return  (a^x) + solve(a,x-1);
    else
        return ((a^(x>>1))+e)*solve(a,x>>1);
}


void ini_d()
{
    int k;

    queue<int> q;
    memset(d,-1,sizeof(d));
    memset(num,0,sizeof(num));

    q.push(sink);
    d[sink]=0;
    num[0]=1;

    while (!q.empty())
    {
        k=q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (d[i] >= n && mat[i][k] > 0)
            {
                d[i] = d[k] + 1;
                q.push(i);
                num[d[i]]++;
            }
        }
    }
}

int findAlowArc(int i)
{
    for (int j = 0; j < n; j++)
    {
        if (mat[i][j] > 0 && d[i] == d[j]+1)
            return j;
    }
    return -1;
}

int reLable(int i)
{
    int mn = n;
    for (int j = 0; j < n; j++)
        if (mat[i][j] > 0)
            mn = min(mn, d[j]+1);
    return mn == n?n:mn;
}

void MaxFlow()
{
    ini_d();
    int flow = 0, i = source,j;
    int delta;
    memset(pre,-1,sizeof(pre));
    while (d[source]<n)
    {
        j=findAlowArc(i);

        if (j>=0)
        {
            pre[j]=i;
            i=j;
            if (i==sink)
            {
                delta = 9999999;
                for (i=sink; i!=source; i=pre[i])
                    delta=min(delta,mat[pre[i]][i]);
                for (i=sink; i!=source; i=pre[i])
                {
                        mat[pre[i]][i] -= delta;
                        mat[i][pre[i]] += delta;
                }
                flow += delta;
            }
        }
        else
        {
            int x=reLable(i);
            num[x]++;
            num[d[i]]--;
            if (num[d[i]]==0)
            {
                //printf("%d\n",flow);     //间隙优化
                return;
            }
            d[i]=x;
            if (i!=source)
                i=pre[i];
        }
    }
    //printf("%d\n",flow);
}

int main()
{
    int cases, nn, kk = 1;
    for(int i=0; i<Max; i++)
    {
        for(int j=0; j<Max; j++)
        {
            if(i==j)
                e.matrix[i][j] = 1;
            else
                e.matrix[i][j] = 0;
            if(i==0 && j==0)
                init.matrix[i][j] = 0;
            else
                init.matrix[i][j] = 1;
        }
    }
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d %d", &nn, &mod);
        Mat ans = solve(init, nn);
        temp = (ans.matrix[0][1]) % mod;
        //printf("%d\n",temp);



        if (temp & 1 || temp == 0)
            printf("Case %d: No\n", kk++);
        else
        {

            memset(mat, 0, sizeof(mat));

            for (int i = 1; i <= temp; i++)
                for (int j = 1; j <= temp; j++)
                    mat[i][j + temp] = 2;


            source = 2 * temp + 1;
            sink = 2 * temp + 2;

            int t1 = 0;
            int t2 = 2 * temp - 1;
            for (int i = 1; i <= temp; i++)
            {
                mat[source][i] = t1++;
                mat[i + temp][sink] = t1++;

                mat[source][temp - i + 1] = t2--;
                mat[2 * temp - i + 1][sink] = t2--;
            }

          //for (int i = 1; i <= 2 * temp; i++)
            //{
               // printf("r[sta][%d] == %d\n", i, r[sta][i]);
               // printf("r[%d][end] == %d\n", i, r[i][end]);
           // }


            n = temp * 2 + 10;
            MaxFlow();

            for (int i = 1; i <= temp; i++)
                for (int j = 1; j <= temp; j++)
                {
                    map[i][j] = mat[i][j + temp] - 1;
                }


            printf("Case %d: Yes\n", kk++);

            for (int i = 1; i <= temp; i++)
            {
                for (int j = 1; j <= temp; j++)
                {
                    if (j != temp)
                        printf("%d ", map[i][j]);
                    else
                        printf("%d\n", map[i][j]);
                }

            }
        }

        //printf("%d\n",ret);
    }
    return 0;
}
