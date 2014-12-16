#include <iostream>
using namespace std;
#define MAX 10001
int a[MAX];
struct pan
{
    int s;
    int s1;
    int f;
}px[MAX],temp;
int cmp(pan n,pan m)
{return n.f<m.f;}

int main()
{
    int x;
    while (cin>>x,x)
    {
        int i,j,len;
        for (i=0;i<x;i++)
        {
            cin>>px[i].s>>px[i].s1;
            px[i].f=px[i].s+px[i].s1;
        }
        sort(px,px+x,cmp);
        a[0]=1;
        i=0;
        int s=1;
        for (j=1;j<x;j++)
        {
            if(px[j].s>=px[i].f)
            {
                s++;
                i=j;
            }
        }
        cout<<s<<endl;        
    }
}
