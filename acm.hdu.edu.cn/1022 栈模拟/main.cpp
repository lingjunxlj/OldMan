#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char in[1001], out[1001];
int main()
{
    int n;
    int flag[2002];
    while (cin>>n>>in>>out)
    {
        memset(flag, -1, sizeof(flag));
        char stack[1001];
        int top = -1, j = 0, i = 0, k = 0;
        while (i < n && j <= n)
        {
            if (stack[top] == out[i] && top != -1)
            {
                i++;
                top--;
                flag[k] = 0;
                k++;
            }
            else
            {
                top++;
                stack[top] = in[j];
                flag[k] = 1;
                j++;
                k++;
            }
        }
        if(k != 2 * n)
        {
            cout<<"No."<<endl<<"FINISH"<<endl;
            continue;
        }
        else
            cout<<"Yes."<<endl;
        for(i = 0; i < n * 2; i++)
            if(flag[i])
                cout<<"in"<<endl;
            else
                cout<<"out"<<endl;
        cout<<"FINISH"<<endl;
    }
}
