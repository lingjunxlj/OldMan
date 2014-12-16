#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
char map[8][8];
int MAX,temp,fg,temp2;
int delta_x[8] = {0,1,1,1,0,-1,-1,-1};
int delta_y[8] = {1,1,0,-1,-1,-1,0,+1};
bool flag[8][8];
void bfs(int p,int q)
{
        int i;
        int a,b;
        temp2=0;
        for (i=0;i<8;i++)
        {
            fg=temp=0;
            a=p;
            b=q;
            while ((a+delta_x[i])>=0&&(b+delta_y[i])>=0&&(a+delta_x[i])<8&&(b+delta_y[i])<8)
            {


                    a=a+delta_x[i];
                    b=b+delta_y[i];
                    if (map[a][b]=='*'||(map[a][b]=='D'&&fg==0))
                    break;
                    if (map[a][b]=='D'&&fg==1)
                    {
                        break;

                    }
                    if (map[a][b]=='L')
                    {
                        temp++;
                        fg=1;

                    }

            }
            if(map[a][b]=='L'||map[a][b]=='*')
            temp=0;
            temp2+=temp;

        }
}
int main()
{
    int n,m=0;
    cin>>n;
    while (n--)
    {
        m++;
        MAX=0;
        int sum=0;
        int i,j;
        for (i=0;i<8;i++)
        for (j=0;j<8;j++)
        cin>>map[i][j];
        for (i=0;i<8;i++)
        for (j=0;j<8;j++)
        if (map[i][j]=='*')
        sum++;
        if (sum==0)
        {
           printf("Case %d: %d\n",m,0);
            continue;
        }
        temp2=0;
        for (i=0;i<8;i++)
        for (j=0;j<8;j++)
        {
            if (map[i][j]=='*')
            {temp2=0;
            bfs(i,j);}
            if (MAX<temp2)
            MAX=temp2;
        }

        printf("Case %d: %d\n",m,MAX);
    }
}
