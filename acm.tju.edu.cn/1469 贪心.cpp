#include <iostream>
using namespace std;
int total,n;
int w[5001],l[5001]; 
int a[5001]; 
void sort(int *l,int *w)
{
    int i,j;
    for(i=0;i<n-1;i++)
    for(j=0;j<n-i-1;j++)
    {
        if(l[j]>l[j+1])
        {
            int temp=l[j];
            l[j]=l[j+1];
            l[j+1]=temp;           
            temp=w[j];
            w[j]=w[j+1];
            w[j+1]=temp;
         } 
         if(l[j]==l[j+1]&&w[j]>w[j+1])
         {
             int temp=w[j];
             w[j]=w[j+1];
             w[j+1]=temp;
         } 
     }
} 
void getaline()
{ 
    sort(l,w);
    int i,j;
    int temp;
    memset(a,0,sizeof(a));
    total=0;  
    for(i=0;i<n;i++)
    if(a[i]==0)
    {
        temp=w[i];
        for(j=i+1;j<n;j++)
        if(a[j]==0&&w[j]>=temp) 
        {
            temp=w[j];
            a[j]=1;                    
        } 
        total++;
    }
    cout<<total<<endl;
}
int main()
{
    int num;
    int i;
    cin>>num;
    for(int j=0;j<num;j++)
    {
        cin>>n;
        for(i=0;i<n;i++)
        cin>>l[i]>>w[i];
        getaline();
        
    } 
    return 0;
}
