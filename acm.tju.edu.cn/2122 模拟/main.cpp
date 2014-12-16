#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n;
    while (cin>>n, n)
    {
        char a, c[100];
        int b, d[200];
        int sum = 0;
        int num = 0;
        memset(d,0,sizeof(d));
        while (n--)
        {
            cin>>a>>b>>c;
            if (strcmp(c,"correct") == 0)
            {
                sum += (b + d[a]);
                num++;
            }
            else
            {
                d[a] += 20;
            }
        }
        cout<<num<<" "<<sum<<endl;
    }
}
