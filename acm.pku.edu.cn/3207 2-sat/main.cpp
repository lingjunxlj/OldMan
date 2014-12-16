#include<iostream>
#include<cmath>
using namespace std;
#define size 1100
int n, m, a, b, v[size], cnt, ee[size][2];
struct edge{int to, next;} e[500000];
void insert(int from, int to)
{
    e[cnt].to = to;
    e[cnt].next = v[from];//每次都插入到最前面
    v[from] = cnt++;
}
int belong[size], num[size], cntnum;
int dfn[size], low[size], index, instack[size], sta[size], top;
void tarjan(int id)
{
    dfn[id] = low[id] = ++index;
    instack[id] = 1; sta[top++] = id;
    int tmp = v[id];
    while(tmp != -1)
    {
        if (!dfn[e[tmp].to])
        {
            tarjan(e[tmp].to);
            if (low[e[tmp].to] < low[id])
				low[id] = low[e[tmp].to];
        }
        else if (instack[e[tmp].to] && dfn[e[tmp].to] < low[id])
            low[id] = dfn[e[tmp].to];
        tmp = e[tmp].next;
    }
    if (dfn[id] == low[id])
    {
        cntnum++;
		do
        {
            tmp = sta[--top];
			instack[tmp] = 0;
            belong[tmp] = cntnum;
            num[cntnum]++;
        }while(tmp != id);

    }
}
int main()
{
    scanf("%d%d", &n, &m);
    memset(v, -1, sizeof(v)); cnt = 0;
    for(int i = 0; i < m ;i++)
    {
        scanf("%d%d", &ee[i][0], &ee[i][1]);
        if (ee[i][0] > ee[i][1]) swap(ee[i][0], ee[i][1]);
    }
    for(int i = 0; i < m; i++)
        for(int j = i + 1; j < m; j++)
        {
            if (ee[i][0] < ee[j][1] && ee[i][0] > ee[j][0] && ee[i][1] > ee[j][1]
            ||  ee[i][1] < ee[j][1] && ee[i][1] > ee[j][0] && ee[i][0] < ee[j][0])
            {
                insert(i, j + m);
                insert(j, i + m);
                insert(j + m, i);
                insert(i + m, j);
            }
        }
    index = top = cntnum = 0;
    memset(num, 0, sizeof(num));
    memset(dfn, 0, sizeof(dfn));
    for(int i = 0; i < 2 * m; i++)
        if (!dfn[i]) tarjan(i);
    bool flag = true;
    for(int i = 0; i < m; i++)
        if (belong[i] == belong[i + m])
        {
            flag = false;
            break;
        }
    if (flag) printf("panda is telling the truth...\n");
    else printf("the evil panda is lying again\n");
    return 0;
}
