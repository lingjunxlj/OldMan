#include <iostream>
#include<stdio.h>
using namespace std;
char str[105];
int main()
{
    int t,j,i,d;
    cin>>t;
    while (t--)
    {
        cin>>str;
        cin>>d;
        for(i=0;str[i];i++)
            str[i]=(str[i]-'a'+d)%26+'a';
        printf("%s\n",str);
    }
    return 0;
}
