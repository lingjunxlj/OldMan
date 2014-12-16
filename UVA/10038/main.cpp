#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int num[3001];
int ans[3001];
bool temp[2<<15];
int main()
{
    int n;
    while(cin>>n)
    {
        for (int i = 0; i < n; i++)
            cin>>num[i];
        memset(temp, 0, sizeof(temp));
        for (int i = 1; i < n; i++)
        {
            ans[i] = num[i] > num[i-1]? (num[i] - num[i-1]):(num[i-1] - num[i]);
            temp[ans[i]] = 1;
        }

        int tp = 0;
        for (int i = 1; i < n; i++)
            if (!temp[i])
            {
                tp = 1;
                break;
            }
        if (tp)
            cout<<"Not jolly"<<endl;
        else
            cout<<"Jolly"<<endl;
    }
}
