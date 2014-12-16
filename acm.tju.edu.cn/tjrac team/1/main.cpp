#include <iostream>
#include <cstdio>
using namespace std;
int c[1000];
int main()
{
   int n,i;
   while(scanf("%d",&n)!=EOF)
   {
       i=0;
       while (n--)
       {
            cin>>c[i++];


       }
       int h=i,j=0;
       while (h--)
       {
        char a;
        a=c[j++];
        cout<<a;
        }

   }
}
