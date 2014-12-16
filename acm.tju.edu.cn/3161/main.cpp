#include <iostream>
using namespace std;

int main()
{
    int n, q;
    int num[502];
    int tp;
    cin>>n>>q;
    num[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin>>tp;
        num[i] =num[i - 1] + tp;
    }
    int a, b;
    while (q--)
    {
        cin>>a>>b;
        cout<<num[b] - num[a - 1]<<endl;
    }
}
