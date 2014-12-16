#include <iostream>
using namespace std;
#define MAX 10200
int first[MAX],last[MAX];
bool flag[MAX];
int main()
{
    int x;
    while (cin>>x&&x)
    {
        int m=0;
        last[m++]=0;
        memset(flag,true,sizeof (flag));
        
            int i=0,j;
            for (i=0;i<x;i++)
            {
                cin>>first[i];
                if (first[i]==0)
                break;
            }
            
            int cc=0;
            for (i=0;i<x;i++)
            {
                flag[first[i]]=false;
                for (j=last[m-1]+1;j<first[i];j++)                
                if (flag[j])
                last[m++]=j;               
                if (first[i]==last[m-1])
                m--;
                else if (first[i]<last[m-1])
                cc=1;
                if (cc)
                break;
            }
            if (cc)
            cout<<"No"<<endl;
            else
            cout<<"Yes"<<endl;
        
       
    }
}
                
            
