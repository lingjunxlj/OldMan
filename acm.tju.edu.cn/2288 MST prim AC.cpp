#include <iostream>
#include <cstdio> 
using namespace std;
#define INF 200000000 
#define MAX 751 
int path[MAX]; 
int matrix[MAX][MAX]; 
int main() 
{ 
    int x[MAX],y[MAX]; 

    int N,M; 
    int p1,p2; 
    int temp1,temp2; 
    int i,j; 

    int cost[MAX]; 
    int min; 
    int u; 

    cin>>N;
    for(i=1;i<=N;i++) 
        scanf("%d%d",&x[i],&y[i]); 

    for(i=1;i<=N;i++) 
        for(j=i;j<=N;j++) 
            if(i==j) 
                matrix[i][i]=INF; 
            else 
            { 
                temp1=x[i]-x[j]; 
                temp2=y[i]-y[j]; 
                matrix[j][i]=matrix[i][j]=temp1*temp1+temp2*temp2; 
            } 

    cin>>M; 
    for(i=1;i<=M;i++) 
    { 
        scanf("%d%d",&p1,&p2); 
        matrix[p1][p2]=matrix[p2][p1]=0; 
    } 
     
    for(i=1;i<=N;i++) 
    { 
        cost[i]=matrix[1][i]; 
        path[i]=1; 
    } 
    cost[1]=-1; 

    for(i=1;i<=N-1;i++) 
    { 
        min=INF; 
        for(j=1;j<=N;j++) 
            if(cost[j]!=-1 && cost[j]<min) 
            { 
                u=j; 
                min=cost[j]; 
            } 
        if(min>0) 
            printf("%d %d\n",path[u],u); 
        cost[u]=-1; 
        for(j=1;j<=N;j++) 
            if(cost[j]!=-1 && cost[j]>matrix[u][j]) 
            { 
                path[j]=u; 
                cost[j]=matrix[u][j]; 
            } 
    } 
   while (1);
} 
