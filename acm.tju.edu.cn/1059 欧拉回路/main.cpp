#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAX = 31;
vector <int> v[MAX];
int in[MAX], out[MAX];
char str[1001];
bool visited[MAX];
int ans, n;

void DFS(int y)
{
    int i;
    ans++;
    visited[y] = 1;
    for (i = 0; i < v[y].size(); i++)
    {
        if (!visited[v[y][i]])
        DFS(v[y][i]);
    }

}
int main()
{
    int x;
    cin>>x;
    while (x--)
    {
        cin>>n;
        int i, j;
        for (i = 0; i <= 26; i++)
        {
            in[i] = 0;
            out[i] = 0;
            v[i].clear();
            visited[i] = 0;
        }
        for (i = 1; i <= n; i++)
        {
            cin>>str;
            int a, b;
            a = str[0] - 'a';
            b = str[strlen(str) - 1] - 'a';

            v[a].push_back(b);
            in[b]++;
            out[a]++;
        }
        int s1, s2, s3;
        int num = 0;
        s1 = 0;
        s2 = 0;
        s3 = 0;
        int start, end;
        for (i = 0; i < 26; i++)
        {
            if (in[i] + out[i] != 0)
            {
                num++;
                if (in[i] + 1 == out[i])
                {
                    s1++;
                    start = i;
                }
                else if (in[i] == out[i])
                {
                    s2++;
                }
                else if (out[i] + 1 == in[i])
                {
                    s3++;
                }
                end = i;
            }
        }
        ans = 0;
        if (s1 != 0)
        DFS(start);
        else
        DFS(end);

        if (num == ans)
        {
            if ((s1 == 1 && s3 == 1 && s2 == num - 2) || s2 == num)
            {
                cout << "Ordering is possible." << endl;
            }
            else
            {
                cout << "The door cannot be opened." << endl;
            }
        }
        else
        {
            cout << "The door cannot be opened." << endl;
        }
    }
}
