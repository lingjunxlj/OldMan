#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
vector<long long> zero;
vector <long long> dnum;
vector <long long> unum;

int main()
{
    int t, x = 1;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        int top = 0, top1 = 0, top2 = 0;
        int temp;
        for(int i = 0; i < n; i++)
        {
            scnaf("%I64d", &temp);
            if (temp == 0)
                zero.push_back(temp);
            if (temp < 0)
                dnum.push_back(temp);
            if (temp > 0)
                unum.push_back(temp);
        }

        if (dnum.size()%2 == 0)
        {
            if (zero.size() == 0)
            {
                 if (unum.size() == 0)
                 {
                     unum.push_back(m - 1);
                 }
                 else
                 {

                 }
            }
        }
    }
}
