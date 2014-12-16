#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int N,T,time[400];
    while (cin>>N>>T)
    {
        int i,j,V[200],D[200];
        for (i=0;i<N;i++)
        cin>>V[i]>>D[i];            
        for (j=0;j<N;j++)
        time[j]=V[j]-ceil(D[j]/T)*T;
        int temp;
        for (i=0;i<N;i++)
        for (j=0;j<N-i;j++)
        {
            if (time[i]>time[j])
            {
                temp=time[i];
                time[i]=time[j];
                time[j]=temp;
            }
        }
        
        int Bool;
        for (i=0;i<N-1;i++)
        if (time[i]>time[i+1])
        Bool=1;
        if (Bool==1)
        cout<<"The zombies eat your brains!";
        else
        for (i=0;i<N;i++)
        cout<<time[i]<<" ";
        cout<<endl;
    }
}
                
                
                
                
                
