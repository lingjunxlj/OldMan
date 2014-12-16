#include <iostream>
#include <cstring>
using namespace std;
int hash[10];
void solve(int x)
{
    while (x)
    {
        hash[x%10]++;
        x /= 10;
    }
}
int main()
{
    memset(hash, 0, sizeof(hash));
    int a, b;
    cin>>a>>b;
    for (int i = a; i <= b; i++)
        solve(i);
    for (int i = 0; i <= 8; i++)
        cout<<hash[i]<<" ";
    cout<<hash[9]<<endl;
}
