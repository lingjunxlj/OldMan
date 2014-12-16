#include <iostream>
#include <string>
using namespace std;
char pre[27],in[27];
void recover(int pi,int pj,int ii,int ij)
{
    if(pi+1>=pj)
    return;  
    int i=ii;                                                                                      
    while(in[i]!=pre[pi])
	i++;
	for(int j=pi;j<pj-1;j++)
	pre[j]=pre[j+1];
	pre[pj-1]=in[i];              
	recover(pi,pi+(i-ii),ii,i);
	recover(pi+(i-ii),pj-1,i+1,ij);
}
int main()
{
	while(cin>>pre>>in)
	{
		int len=strlen(pre);
		recover(0,len,0,len);
		cout<<pre<<endl;
	}
}
