#include<iostream>
#include<algorithm>
using namespace std;
struct node {
        int pro;
        int end;
        }a[10001];
int cmp(node a,node b)
{return a.end<b.end;}
int main()
{
    int sum;
    int i,j;
    int n;
    int pro;
    while(cin>>n,n!=0)
    {
        for(i=0;i<n;i++)
        {
            cin>>a[i].pro>>a[i].end;
            a[i].end=a[i].pro+a[i].end;
        }
        sort(a,a+n,cmp);
        sum=1;
        pro=a[0].end;
        for(i=1;i<n;i++)
        if(a[i].pro>=pro) 
        {  
            pro=a[i].end;
            sum++;
        }
        cout<<sum<<endl;
    }
} 
