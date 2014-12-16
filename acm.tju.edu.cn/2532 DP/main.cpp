#include <iostream>
#include <string>
using namespace std;
const int MAX = 301;
int c[MAX][MAX];
int min(int a,int b,int c)
{ return (a < b?a:b) < c?(a < b?a:b):c;}
int main()
{
    string a, b;
    int n, m;
    while(cin >> n)
    {
        getchar();
        getline(cin,a);
        cin >> m;
        getchar();
        getline(cin,b);
        int i, j;
        for(i = 0; i <= m; i++)
        {
            c[i][0] = i;
            c[0][i] = i;
        }
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= m; j++)
            {
                if(a[i - 1] == b[j - 1])
                {
                    c[i][j] = min(c[i - 1][j - 1] , c[i][j - 1] + 1, c[i - 1][j] + 1);
                }
                else
                {
                    c[i][j] = min(c[i - 1][j - 1],c[i][j - 1], c[i - 1][j]) + 1;
                }
            }
        }
        cout<<c[n][m]<<endl;
    }
}
