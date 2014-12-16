#include<iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    int a;
    cin>>a;
    while(a--)
    {
        int m,n;
        cin>>n>>m;
        int in[200];
        int p=n;
        for(int i=0;i<=n;i++)
            in[i]=i;
        for(int i=0;i<m;i++)
            {
                int t,r;
                cin>>t>>r;
                if(in[t]!=in[r])
                    {
                        int min=(in[t]<in[r]?in[t]:in[r]);
                        int max=(in[t]>in[r]?in[t]:in[r]);
                        for(int j=1;j<n+1;j++)
                            if(in[j]==max)
                                in[j]=min;
                        p--;
                    }
            }
            cout<<p<<endl;       
    }
    system("pause");
	return 0;
}
