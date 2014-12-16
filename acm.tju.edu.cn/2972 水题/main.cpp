#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int dist[1000001];
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n, i;
        cin>>n;
        long long sum = 0;
        for (i = 0; i < n; i++)
        cin>>dist[i];

        sort(dist, dist + n);
        int mid = (n) / 2;
        for (i = 0; i < n; i++)
        {
            sum += abs(dist[i] - dist[mid]);
        }
        cout<<sum<<endl;
    }
}
