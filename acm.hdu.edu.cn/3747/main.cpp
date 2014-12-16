#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char str1[1000], str2[1000];
int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        cin>>str1>>str2;
        int min = 0x7ffff;
        int ans;
//////////////////////////////
        ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (str1[i] != str2[i])
                ans ++;
        }
        if (ans < min)
            min = ans;
        //cout<<"min  ="<<min<<endl;
////////////////////////////////////
        ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (str2[i] != '1')
                ans ++;
        }
        ans++;
        if (ans < min)
            min = ans;
        //cout<<"min  ="<<min<<endl;
//////////////////////////////////////
        ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (str2[i] != '0')
                ans ++;
        }
        ans += 2;
        if (ans < min)
            min = ans;
        //cout<<"min  ="<<min<<endl;
/////////////////////////////////
        ans = 0;
        //cout<<str1<<endl;
        for (int i = 0; i < n; i++)
        {
            if (str1[i] == '1')
                str1[i] = '0';
            else if (str1[i] == '0')
                str1[i] = '1';
        }
        //cout<<str1<<endl;
        for (int i = 0; i < n; i++)
        {
            if (str1[i] != str2[i])
                ans ++;
        }
        ans ++;
        if (ans < min)
            min = ans;
        //cout<<"min  ="<<min<<endl;
////////////////////////////////////////
        cout<<min<<endl;
    }
}
