#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char str[4];
int t, i;
int Josephus(int n)
{
    int i = 1;

    while(i <= n)
    i<<=1;

    return ( (n - (i>>1) )<<1) + 1;
}

int main()
{
    while(cin>>str)
    {
        if(strcmp(str, "00e0") == 0)
        break;

        t = (str[0] - '0') * 10 + str[1] - '0';
        for(;str[3] > '0'; str[3]--)
        t *= 10;

        cout<<Josephus(t)<<endl;
    }
    return 0;
}
