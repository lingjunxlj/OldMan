#include <iostream>

using namespace std;
bool mark[20001];
struct node
{
    int x;
    int y;
}stick[20001];
bool cmp(node a, node b)
{
    return a.x < b.x;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &stick[i].x, &stick[i].y);
    memset(mark, 0, sizeof(mark));
    sort(stick, stick + n, cmp);
    int tmp =  stick[0].y;
    int  t = 0;
    for (int i = 0; i < n; i++)
    {
        if (mark[i] == 1)
        continue;

        tmp =  i;
        t++;
        for (int j = i + 1; j < n; j++)
        {
            if (stick[tmp].y <= stick[j].x && mark[j] == 0)
            {
                 tmp = j;
                 mark[j] = 1;
            }

        }

    }
    printf("%d\n", t);

}
