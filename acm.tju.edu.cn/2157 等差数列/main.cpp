#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    int n, Case, num, i = 0;
    cin>>n;
    while (n--)
    {
        cin>>Case>>num;
        i++;
        int res = 0;
        for (int i = 2; i < sqrt(num * 2.0); i++)
        {
            if ((num - i * (i - 1) / 2) % i == 0)
            res++;
        }

        cout<<i<<" "<<res<<endl;
    }
}
