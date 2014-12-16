/*
 * File:   PKU 2449 Remmarguts' Date
 * Author: xiaotian @ hnu
 * Created on 2010��10��5��, ����10:25
 * ��⣺��� k ��·��dijkstra + A* ����
 */
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
using namespace std;
const int N = 1011;
const int inf = 0x7ffffff;
int n, m, s, t, k, dis[N];
struct node {
    int v, l;
    node(int v, int l) : v(v), l(l) {
    }
    inline bool operator<(const node & b) const {
        return l + dis[v] > b.l + dis[b.v]; //�����ǶԹ��ۺ�����ʹ�ã�ʹ��·����̵��ȳ���
    }
};
vector<node> p[N]; /* ͼ���ڽӱ��ʾ����ͼ�� */
vector<node> g[N]; /* ��ͼ */
int getint() //���getchar������Դ�����������ǳ����ã������������Ч�ʲ��ߵ��㷨
{
    int ret = 0;
    char tmp;
    while (!isdigit(tmp = getchar()));
    do {
        ret = (ret << 3)+(ret << 1) + tmp - '0';
    } while (isdigit(tmp = getchar()));
    return ret;
}
void dijkstra() //�����е㵽�յ�����·��
{
    int i, u, mark[N];
    for (i = 1; i <= N; i++)dis[i] = inf;
    memset(mark, 0, sizeof mark);
    priority_queue<node> heap;
    dis[t] = 0;
    heap.push(node(t, 0));
    while (!heap.empty()) {
        u = heap.top().v;
        heap.pop();
        if (mark[u])continue;
        mark[u] = 1;
        for (i = 0; i < p[u].size(); i++)
            if (!mark[p[u][i].v] && dis[u] + p[u][i].l < dis[p[u][i].v]) {
                dis[p[u][i].v] = dis[u] + p[u][i].l;
                heap.push(node(p[u][i].v, dis[p[u][i].v]));
            }
    }
}
int A_star() //A*����
{
    int u, i, len, c[N];
    if (dis[s] == inf)return -1;
    priority_queue<node> heap;
    memset(c, 0, sizeof c);
    heap.push(node(s, 0));
    while (!heap.empty()) {
        u = heap.top().v;
        len = heap.top().l;
        heap.pop();
        c[u]++;
        if (c[t] == k)return len;
        if (c[u] > k)continue;
        for (i = 0; i < g[u].size(); i++)
            heap.push(node(g[u][i].v, len + g[u][i].l));
    }
    return -1;
}
int main() {
    int i, u, v, w;
    while (scanf("%d %d", &n, &m) != EOF) {
        for (i = 0; i < m; i++) {
            u = getint();
            v = getint();
            w = getint();
            g[u].push_back(node(v, w));
            p[v].push_back(node(u, w));
        }
        s = getint();
        t = getint();
        k = getint();
        if (s == t) k++;  /* ��� s==t ����ô������ k+1 ��· */
        dijkstra();
        printf("%d\n", A_star());
    }
    return 0;
}
