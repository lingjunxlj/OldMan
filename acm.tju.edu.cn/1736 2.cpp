#include<iostream>
#include<memory>
#include<queue>
#include <cstdlib>
using namespace std;

int dir[8][2] = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{-1,2},{-1,-2},{1,-2}
};    

int flag[300][300]; 

struct  node
{
    int x,y,step; 
};

int main()
{
     int x;
     cin>>x;
     while (x--)
     {
	 	int a,b,c,d,e;
    	node N,P;
		queue<node> Q;
  	    memset(flag,0,90000);
     	cin>>e>>a>>b>>c>>d;
     	N.x=a;N.y=b;N.step=0;
     	Q.push(N);     
     	flag[a][b]=1;  
     	while(!Q.empty())
     	{
          	N=Q.front();Q.pop();  
          	if(N.x==c&&N.y==d)  
             	break;
         	 for(int i=0;i<e;i++)   
          	{
               int tx=N.x+dir[i][0];
               int ty=N.y+dir[i][1];
               if(tx>=0&&tx<e&&ty>=0&&ty<e&&flag[tx][ty]==0) 
               {
                    P.x=tx;P.y=ty;P.step=N.step+1;
                    Q.push(P);
                    flag[tx][ty]=1;  
               }
          	}
    	}cout<<N.step<<endl;
	}
   
   
}
