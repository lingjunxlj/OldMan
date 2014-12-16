#include <iostream>
#include <cstdio>
using namespace std;
char str[100000];
void jz(int x,int p)
{
    int temp,i=0;
    while (x>0)
    {
       str[i++]=x%p+32;
       x/=p;
    }
}

int main()
{
    int m;
    scanf("%d",&m);
    while (m--)
    {
        int n,p;
        scanf("%d %d",&n.&p);

