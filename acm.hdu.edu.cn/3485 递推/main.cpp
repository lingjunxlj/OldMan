#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
long long one[10001], zero[10001];
long long dp[10001];
int main()
{

    one[1] = 1;
    zero[1] = 1;
    dp[1] = 2;
    one[2] = 2;
    zero[2] = 2;
    dp[2] = 4;
    for (int i = 3; i <= 10000; i++)
    {
          zero[i] = (zero[i - 1] + one[i - 1]) % 9997;
          one[i] = (one[i - 1] + zero[i - 2])%9997;
          dp[i] = zero[i]+ one[i];
          //cout<<dp[i]<<endl;
    }
    int n;
    while(cin>>n)
    {
        if (n == -1)
            break;
        cout<<dp[n]%9997<<endl;

    }
}
