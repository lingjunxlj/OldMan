#include <iostream>
#include <algorithm>
using namespace std;
int num[10001];
int main()
{
    int n;
    while(cin>>n)
    {
        for (int i = 0; i < n; i++)
           cin>>num[i];
        sort(num, num + n);
        cout<<num[n/2]<<endl;
    }
}
