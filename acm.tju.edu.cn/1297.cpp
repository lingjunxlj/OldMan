#include<iostream>
using namespace std;
int main()
{
    int n,o=0;
    cin>>n;
while(o<n)
{
    int m,i=0;
    cin>>m;
    int sh[1000];
    for(i=0;i<m;i++)
        cin>>sh[i];
    	for(i=0;i<m-1;i++)
        for(int j=0;j<m-1;j++)
            if(sh[j]>sh[j+1])
            {
                int d=sh[j];
                sh[j]=sh[j+1];
                sh[j+1]=d;
            }
   int max=0,s;
		for (i=0;i<m;i++)
		{
			s=sh[i]*(m-i);
			if (s>max)
			max=s;
		}
    cout<<max<<endl;
    o++;
}
return 0;
}
