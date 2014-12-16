#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int queue[101];
int head, len;
int max()
{
    int i, m = queue[head], p = (head + 1) % len, m_i = head;
    for(i = 1; i < len; i++)
    {
        if(queue[p] > m)
        {
            m = queue[p];
            m_i = p;
        }
        p = (p + 1) % len;
    }
    return m_i;
}

int out()
{
    int a;
    head = max();
    a = head;
    queue[head] = -1;
    head = (head + 1) % len;
    return a;
}

int main()
{
    int i, count, x, n, m;
    cin>>x;
    while (x--)
    {
        cin>>n>>m;
        len = n;
        head = 0;
        for(i = 0; i < len; i++)
        {
            cin>>queue[i];
        }
        count = 1;
        int a;
        while (out() != m)
        {
            count++;
        }
        cout<<count<<endl;
    }
}
