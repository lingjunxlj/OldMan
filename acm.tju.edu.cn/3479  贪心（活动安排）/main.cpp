#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
struct Node
{
    int s;
    int e;
}ap[50001];
bool cmp(Node x, Node y)
{
    return x.e < y.e;
}
bool a[50001];
int main()
{
    int n, i, j;
    cin>>n;
    for (i = 1; i <= n; i++)
    {
        cin>>ap[i].s>>ap[i].e;
    }
    sort(ap, ap+n, cmp);
    memset(a, 0, sizeof(a));
    a[1]=true;
    j=1;
    int count=1;
    for (i = 2; i <= n; i++)
    {

        if (ap[i].s >= ap[j].e)
        {

            a[i]=true;
            j = i;
            count++;
        }
        else a[i]=false;
    }
    cout<<count<<endl;
}





