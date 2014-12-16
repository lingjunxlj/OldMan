#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 101;
int n;
struct M
{
    int a;
    int b;
    int c;
} m[N];

int test(int x, int y)
{
    int b[4], c[4], j, i, k = 0, s = 0, f[4] = {0,0,0,0};
    c[0]=x%10;
    c[1]=(x/10)%10;
    c[2]=(x/100)%10;
    c[3]=x/1000;

    b[0]=m[y].a%10;
    b[1]=(m[y].a/10)%10;
    b[2]=(m[y].a/100)%10;
    b[3]=m[y].a/1000;

    for(i = 0; i < 4; i++)
    {
        if(b[i] == c[i])
            k++;
    }
    if(k != m[y].c)
        return 1;

    for(i = 0; i < 4; i++)
        for(j = 0; j < 4; j++)
        {
            if(b[i] == c[j] && f[j] == 0)
            {
                s++;
                f[j] = 1;
                break;
            }
        }
    if(s == m[y].b)
        return 0;
    else
        return 1;
}

int main()
{
    int i, j, k, sign, result;
    while(cin>>n&&n)
    {
        k = 0;
        for(i = 0; i < n; i++)
            cin>>m[i].a>>m[i].b>>m[i].c;

        for(i = 1000; i <= 9999; i++)
        {
            sign=1;
            for(j = 0; j < n; j++)
            {
                sign = test(i,j);
                if(sign)
                    break;
            }
            if(!sign)
            {
                k++;
                result = i;
            }
        }
        if(k == 1)
            cout<<result<<endl;
        else
            cout<<"Not sure"<<endl;
    }
    return 0;
}
