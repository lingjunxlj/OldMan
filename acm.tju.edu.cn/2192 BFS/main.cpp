#include<iostream>
using namespace std;

int direct[8][8]={-1,0,-1,1,0,1,1,1,1,01,-1,0,-1,-1,-1}; //八个方向
struct node
{
 int x;
 int y;
}queue[1000];  //队列的结构体


int main()
{
 int m,n,i,j,k;
 char map[10][10];  //图
 int mark[10][10];  //标记
    while(cin>>m>>n&&(m||n))
 {
  int length=0,area=0,f=0,r=0,num=0;
  memset(map,'.',sizeof(map));
  memset(mark,0,sizeof(mark));
  for(i=1;i<=m;i++)
   for(j=1;j<=n;j++)
    cin>>map[i][j];
   for(i=1;i<=m;i++)
    for(j=1;j<=n;j++)
    {
     if(map[i][j]=='X'&&mark[i][j]==0)
     {
      mark[i][j]=1;
      area++;
      queue[r].x=i;  //入队
      queue[r].y=j;
      r++;
      while(f!=r)  //队非空
      {
       int x11=queue[f].x;  //出队
       int y11=queue[f].y;
       f++;
       for(k=0;k<8;k++)  //8个方向广搜
       {
        int x1=i+direct[k][0];
        int y1=j+direct[k][1];
        if(map[x1][y1]=='x'&&mark[x1][y1]==0)
        {
         mark[x1][y1]=1;
         area++;
         queue[r].x=x1;
         queue[r].y=y1;
         r++;
        }
        else if(map[x1][y1]=='.'&&mark[x1][y1]==0)
        {
         mark[x1][y1]=1;
         if(x1==i||y1==j) //周长增加的条件
          length++;
        }
       }//for
      }//while
      num +=length/area;
     }//if


    }//for
    if(num<=(m*n)/4)
     cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
 }//while
 return 0;
}
