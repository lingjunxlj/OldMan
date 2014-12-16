#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
struct node
{
    char str[100];
    int num;
    int step;
}first, temp, Q[10000];
int len, ans, hash[100000];
int get_num(char str[])
{
    int num = 0;
    for (int i = 0; i < len; i++)
    {
        if (str[i] == 'r')
            num = num * 3;
        if (str[i] == 'b')
            num = num * 3 + 2;
        if (str[i] == 'g')
            num = num * 3 + 1;
    }
    return num;
}
bool judge(int num)
{
    if (num == 0 || num == ans || num == ans/2)
        return true;
    return false;
}
char change_word(char a, char b)
{
    int c = a + b, res;
    if (c == 217)
        res = 98;
    else if (c == 201)
        res = 114;
    else
        res = 103;
    return res;
}
void BFS()
{
    int head, tail;
    head = tail = 0;
    Q[tail++] = first;
    while(head < tail)
    {
        first = Q[head];
        head++;
        for (int i = 1; i < len; i++)
        {
            if (first.str[i - 1] != first.str[i])
            {
                temp = first;
                temp.str[i] = temp.str[i - 1] = change_word(temp.str[i - 1], temp.str[i]);
                temp.num = get_num(temp.str);
                temp.step++;
                if (judge(temp.num))
                {
                    printf("%d\n", temp.step);
                    return;
                }
                else
                {
                    if (!hash[temp.num])
                    {
                        Q[tail++] = temp;
                        hash[temp.num] = 1;
                    }
                }
            }
        }
    }
    printf("No solution!\n");
}
int main()
{
    int t;
    scanf("%d", &t);

    while(t--)
    {
        scanf("%s", first.str);
        len = strlen(first.str);
        ans = pow(3, len) - 1;
        first.num = get_num(first.str);
        if (judge(first.num))
        {
            printf("0\n");
            continue;
        }
        for (int i = 0; i < 99900; i++)
            hash[i] = 0;
        //memset(hash, 0, sizeof(hash));
        hash[first.num] = 1;
        first.step = 0;
        BFS();
    }
    return 0;
}
