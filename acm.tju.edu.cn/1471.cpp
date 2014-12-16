#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int score[150][150];
int map[5][5]={
    5, -1, -2, -1, -3,
    -1, 5, -3, -2, -4,
    -2, -3, 5, -2, -2,
    -1, -2, -2, 5, -1,
    -3, -4, -2, -1, -127
};
int main()
{
    int x;
    cin>>x;
    while (x--)
    {
        int lena,lenb,i,j,a[150],b[150];
        char a1[150],b1[150];
        cin>>lena;
        cin>>a1;
        for (i=0;i<lena;i++)
        {
            if (a1[i]=='A')
            a[i]=a1[i]-'A';
            if (a1[i]=='T')
            a[i]=a1[i]-'A';
            if (a1[i]=='G')
            a[i]=a1[i]-'A';
            if (a1[i]=='C')
            a[i]=a1[i]-'A';
        }
        cin>>lenb;
        cin>>b1;
        for (i=0;i<lenb;i++)
        {
            if (b1[i]=='A')
            b[i]=b1[i]-'A';
            if (a1[i]=='T')
            b[i]=b1[i]-'A';
            if (b1[i]=='G')
            b[i]=b1[i]-'A';
            if (b1[i]=='C')
            a[i]=b1[i]-'A';
        }
        score[0][0]=0;
        for (i=0;i<lena;i++)
        score[i][0]=score[i-1][0]+map[a[i]][4];
        for (i=0;i<lenb;i++)
        score[0][i]=score[0][i-1]+map[4][b[i]];
        for (i=1;i<=lena;i++)
        for (j=1;j<=lenb;j++)
        {
            score[i][j]=score[i][j]+map[a[i-1]][b[j-1]];
            if (score[i][j]<score[i-1][j]+map[a[i]][4])
            score[i][j]=score[i-1][j]+map[a[i-1]][4];
            if (score[i][j]>score[i-1][j]+map[4][b[j-1]])
            score[i][j]=score[i-1][j]+map[4][b[j-1]];
        }
        
        printf ("%d\n",score[i][j]);
    }
}
        
        
        
        
        
        
        
