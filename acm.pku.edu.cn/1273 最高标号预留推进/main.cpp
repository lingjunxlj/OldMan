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
const int size = 501;
const int MAX = 1 << 15;
int start;
int end;
int graph[size][size];
int label[size]; //标号
bool visited[size];
int n, m;
bool bfs(int st, int ed)
{
        memset(label, -1, sizeof(label));
        memset(visited, false, sizeof(visited));
        label[st] = 0;
        visited[st] = true;
        vector<int> plist;
        plist.push_back(st);
        while (plist.size())
        {
                int p = plist[0];
                plist.erase(plist.begin());
                for (int i=0; i<size; i++)
                {
                        if (graph[i][p] > 0 && !visited[i])
                        {
                                plist.push_back(i);
                                visited[i] = true;
                                label[i] = label[p] + 1;
                        }
                }
        }
        if (label[ed] == -1)
        {
                return false;
        }
        return true;
}

int inflow[size]; //流入量

int maxFlow()
{
        memset(inflow, 0, sizeof(inflow));

        //hights
        bfs(size - 1, 0); //end point: size - 1, start point: 0
        memset(visited, false, sizeof(visited));

        //prepare()
        vector<int> plist;
        for (int i=0; i<size; i++)
        {
                if(graph[start][i] > 0)
                {
                        inflow[i] = graph[start][i];
                        graph[start][i] -= inflow[i];
                        graph[i][start] += inflow[i];
                        if(!visited[i])
                        {
                                plist.push_back(i);
                                visited[i] = true;
                        }
                }
        }
        while (plist.size())
        {
                int p = plist[0];
                plist.erase(plist.begin());
                visited[p] = false;
                int minLabel = -1;
                for (int i=0; i<size; i++)
                {
                        if(graph[p][i] > 0)
                        {
                                if(label[p] == label[i] + 1)
                                {
                                        int flow = min(inflow[p], graph[p][i]);
                                        inflow[p] -= flow;
                                        inflow[i] += flow;
                                        graph[p][i] -= flow;
                                        graph[i][p] += flow;

                                        if (!visited[i] && inflow[i] > 0)
                                        {
                                                plist.push_back(i);
                                                visited[i] = true;
                                        }
                                }
                        }
                }
                if (inflow[p] > 0 && p != end)
                {
                        for (int i=0; i<size; i++)
                        {
                                if (graph[p][i] > 0)
                                {
                                        if (minLabel == -1 || minLabel > label[i] + 1)
                                        {
                                                minLabel = label[i] + 1;
                                        }
                                }
                        }
                        if(!visited[p] && minLabel != -1 && minLabel < size)//minLabel < size, 这个条件需要加上, 因为经过测试发现有死循环的可能
                        {
                                for (int i=0; i<size; i++)
                                {
                                        if (label[i] + 1 == minLabel && graph[p][i] > 0)
                                        {
                                                visited[p] = true;
                                                label[p] = minLabel;
                                                plist.push_back(p);
                                                break;
                                        }
                                }
                        }
                }
        }
        return inflow[end];
}
int main()
{
    //freopen("mf1.in","r",stdin);
   // freopen("my.txt","w",stdout);
    int s, e, c;
    while(scanf("%d %d",&n, &m) != EOF)
    {
        start = 0;
        end = m - 1;
        memset(graph,0,sizeof(graph));
        for(int i=0; i < n; i++)
        {
            scanf("%d %d %d",&s,&e,&c);
            graph[s-1][e-1] += c;
        }
        printf("%d\n",maxFlow());
    }
    return 0;
}
