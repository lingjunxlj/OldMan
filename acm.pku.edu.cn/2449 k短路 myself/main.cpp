#include <iostream>
#include <cstdio>
#include <memory.h>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 11050;

struct Node
{
    int vex, weight;
}node;

priority_queue <Node> heap;
vector <Node> num1[MAXN];
vector <Node> num2[MAXN];

int st, end, k, sum[MAXN];
int cnt[MAXN];
bool flag[MAXN];
int n, m;


bool operator < (Node a, Node b)
{
    return a.weight + sum[a.vex] > b.weight + sum[b.vex];
}

int getint() //这个getchar的输入对大数据量输入非常有用，甚至可以挽救效率不高的算法
{
    int ret = 0;
    char tmp;
    while (!isdigit(tmp = getchar()));
    do {
        ret = (ret << 3)+(ret << 1) + tmp - '0';
    } while (isdigit(tmp = getchar()));
    return ret;
}

void dijkstra()
{
    memset(flag, 0, sizeof(flag));
    memset(sum, -1, sizeof(sum));

    node.vex = end;
    node.weight = 0;
    sum[end] = 0;
    //cout<<"node.vex="<<node.vex<<endl;
    heap.push(node);

    while(!heap.empty())
    {
        node = heap.top();
        //cout<<"node.vex="<<node.vex<<endl;
        heap.pop();

        if (flag[node.vex])
            continue;
        flag[node.vex] = true;

        int size = num2[node.vex].size();
        int i;
        //cout<<"size="<<size<<endl;
        for ( i = 0; i < size; i++)
        {
            int u = num2[node.vex][i].vex;
            //cout<<"u="<<u<<endl;
            int temp = num2[node.vex][i].weight + node.weight;
            if (!flag[u] && (temp < sum[u] || sum[u] == -1))
            {
                sum[u] = temp;
                //cout<<"sum[u]="<<sum[u]<<endl;
                Node tp;
                tp.vex = u;
                tp.weight = sum[u];
                heap.push(tp);
            }
        }
    }
}
void clear()
{
    while( !heap.empty() )
		heap.pop();
}
int astar()
{
    if (sum[st] == -1)
        return -1;
    while( !heap.empty() )
		heap.pop();
    //clear();

    memset(cnt, 0, sizeof(cnt));

    node.vex = st;
    node.weight = 0;
    heap.push(node);

    while(!heap.empty())
    {
        node = heap.top();
        heap.pop();
        cnt[node.vex]++;

        if (cnt[node.vex] == k)
            return node.weight + sum[node.vex];

        //if (cnt[node.vex] > k)
            //continue;

        int size = num1[node.vex].size();
        int i;
        for ( i = 0; i < size; i++)
        {
            Node tp;
            tp.vex = num1[node.vex][i].vex;
            tp.weight = num1[node.vex][i].weight + node.weight;
            heap.push(tp);
        }
    }
    return -1;
}
int main()
{

    n = getint();
    m = getint();
    //scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int temp1, temp2;
        temp1 = getint();
        temp2 = getint();
        node.weight = getint();
        //cin>>temp1>>temp2>>node.weight;
        //scanf("%d%d%d", &temp1, &temp2, &node.weight);

        temp1--, temp2--;

        node.vex = temp2;
        num1[temp1].push_back(node);

        node.vex = temp1;
        num2[temp2].push_back(node);
    }
    //cin>>st>>end>>k;
    //scanf("%d%d%d", &st, &end, &k);
    st = getint();
    end = getint();
    k = getint();
    st--, end--;

    if (st == end) //重合时，本身就是最短的
        k++;
    dijkstra(); // 末点到各个点的最短距离，为估价函数做预处理
    printf("%d\n",astar());
    return 0;
}
