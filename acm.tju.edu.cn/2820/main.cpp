#include <iostream>
#include <cstring>
using namespace std;
bool num[10010];
int main()
{
    int f, k;
    memset(num, 0, sizeof(num));
    cin>>f>>k;
    int a, b;
    while(k--)
    {
        cin>>a>>b;
        int tp = a;
        while (tp <= f)
        {
            num[tp] = 1;
            tp += b;
        }
    }
    int sum = 0;
    for (int i = 1; i <= f; i++)
        if (num[i] == 1)
            sum++;
    cout<<f - sum<<endl;
}
