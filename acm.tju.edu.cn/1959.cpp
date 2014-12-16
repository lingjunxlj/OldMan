#include <iostream>
using namespace std;
int b[8][2]={{-1,0},{1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
char a[101][101];
int m,n;
int  panduan(int i,int j)
{
    int k;
    a[i][j]='*';
    for(k=0;k<8;k++)
    {
        if(i+b[k][0] < 0 || i+b[k][0] > m || j+b[k][1] < 0 || j+b[k][1] > n)
        continue;
        if(a[i+b[k][0]][j+b[k][1]] == '@')
        {
            panduan(i+b[k][0],j+b[k][1]);
        }
    }
}
int main()
{
    int i,j;
    int sum;
    while(cin>>m>>n)
    {
        sum=0;
        if(m==0&&n==0)
        break;
        for(i=0;i<m;i++)
        cin>>a[i];
        for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        if(a[i][j]=='@')
        {
            sum++;
            panduan(i,j);
        }
        cout<<sum<<endl;
    }
    return 0;
} 
