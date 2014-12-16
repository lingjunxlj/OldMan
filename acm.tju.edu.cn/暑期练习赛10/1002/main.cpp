#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
using namespace std;
char a1[10110][111], b1[10110][111], c1[10110][111], d[10110][111];
map <string,int> e;
map <string,int> f;
int main()
{
    int a, b, c;
    while (cin>>a>>b>>c)
    {
        int i, j, k;
        e.clear();
        f.clear();
        for (i = 0; i < a; i++)
        {

            cin>>a1[i];
            e[a1[i] ]= 1;
        }
        for (i = 0; i < b; i++)
        cin>>b1[i];
        for (i = 0; i < c; i++)
        {
            cin>>c1[i];
            f[c1[i] ]= 1;
        }
        k = 0;
        for (i = 0; i < b; i++)
            if (f[b1[i]] != 1 && e[b1[i]] == 1)
                strcpy(d[k++],b1[i]);
        if (k == 0)
        printf("No enemy spy\n");
        else
        {
            for (i = 0; i < k-1; i++)
                cout<<d[i]<<" ";
            cout<<d[k-1];

            cout<<endl;
        }
    }
}
