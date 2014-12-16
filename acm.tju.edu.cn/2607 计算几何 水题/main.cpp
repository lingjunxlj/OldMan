#include <cmath>
#include <cstdio>
using namespace std;
const int N = 1001;
struct slist
{
    double x, y, z;
}slist[N];

struct tlist
{
    double x, y, z, a;
}tlist[N];

int ns, nt;


double sqr(double x)
{
    return x*x;
}
int check(int i, int j)
{
    double v = slist[i].x * tlist[j].x + slist[i].y * tlist[j].y + slist[i].z * tlist[j].z;

    v /= sqrt(sqr(slist[i].x)+sqr(slist[i].y)+sqr(slist[i].z));
    v /= sqrt(sqr(tlist[j].x)+sqr(tlist[j].y)+sqr(tlist[j].z));

    if(v < 0)
    return 0;

    double ang = acos(v);

    if(ang < tlist[j].a)
    return 1;

    return 0;
}

int main()
{
    int i, j;
    while (scanf("%d", &ns) && ns)
    {
        int ans = 0;
        for (i = 0; i < ns; i++)
        {
            scanf("%lf%lf%lf", &slist[i].x, &slist[i].y, &slist[i].z);
        }
        scanf("%d", &nt);
        for (i = 0; i < nt; i++)
        {
            scanf("%lf%lf%lf%lf", &tlist[i].x, &tlist[i].y, &tlist[i].z, &tlist[i].a);
        }
        for (i = 0; i < ns; i++)
            for (j = 0; j < nt; j++)
                if (check(i, j))
                {
                    ans++;
                    break;
                }
        printf("%d\n", ans);
    }
    return 0;
}
