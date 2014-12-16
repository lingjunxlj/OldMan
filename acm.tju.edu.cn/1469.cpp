#include <iostream>
using namespace std;
struct node
{
    int l;
    int w;
    bool flag;
}stick[5001];
bool cmp(node a,node b)
{    
    if(a.l == b.l)        
    return a.w<b.w;    
    return a.l<b.l;
}
int main()
{
    int x,n;
    cin>>x;
    while (x--)
    {
        cin>>n;
        int i,sum=0,j,temp;
        for (i=0;i<n;i++)
        {
            cin>>stick[i].l>>stick[i].w;
            stick[i].flag=true;
        }
        sort(stick,stick+n,cmp);
        for (i=0;i<n;i++)
        {
            if (stick[i].flag)
            temp=stick[i].w;
            for (j=i+1;j<n;j++)
            if (stick[j].flag&&temp<=stick[j].w)
            {
                stick[j].flag=false;
                temp=stick[j].w;
            }
            sum++;
        }
        cout<<sum<<endl;
    }
}
                
                
                
                
                
        
        
