#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int b[100020];
int e[100020];
bool mk[100020];

int main()
{

    int t;
    int n, ans;
    cin>>t;
    while(t--)
    {
        ans=0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d%d", &b[i], &e[i]);

        sort(b, b + n);
        sort(e, e + n);
        int i = 0, j = 0;
        while(i < n)
        {
            if(e[j] <= b[i])
            {
                j++;
                i++;
            }
            else
            {
                i++;
                ans++;
            }

        }
        cout<<ans<<endl;
    }
    return 0;
}

