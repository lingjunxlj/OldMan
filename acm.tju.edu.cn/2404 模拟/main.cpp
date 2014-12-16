#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 100001;
int num[MAX];
bool flag;
bool cmp(const int a, const int b)
{
    return a > b;
}
int main()
{
    int n, l, i;
    cin>>n>>l;
    for (i = 0; i < n; i++)
    cin>>num[i];

    sort (num, num + n, cmp);
    int tail = n-1;
    int head = 0;

    do
    {
        flag = 0;
        for (i = head; i < tail; i++)
        {
            if (num[i] + num[tail] <= l)
            {
                head = i + 1;
                tail--;
                flag = 1;
                break;
            }
        }

    }while (flag);
    cout<<tail+1<<endl;
}
