#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int> >num;
int main()
{
    int n;
    scanf("%d",&t);
    while (t--)
    {
        int n,i,j;
        scanf("%d",&n);
        while (n--)
        {
            int temp;
            for (i=0;i<n;i++)
            {
                scanf("%d",&temp);
                num.push(temp);
            }
        }
        int m;
        scanf("%d",&m);
        while (m--)
        {
            char str[100];
            int temp2;
            scanf("%s",str);
            scanf("%d",temp2);
            if (str[0]=='a')
            num.push(temp2);
            if (str[0]=='m')
            {
                if

