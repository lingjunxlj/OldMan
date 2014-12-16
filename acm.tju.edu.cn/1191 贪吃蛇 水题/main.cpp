#include <iostream>
using namespace std;
int main()
{
    int a[50][50],m,x1,y1,x2,y2,i,j,k;
    char c;
    cin>>m;
    while (m!=0)
    {
        for(x1=0;x1<50;x1++)
        for (y1=0;y1<50;y1++)
        a[x1][y1]=0;
        for (x1=10;x1<29;x1++)
        a[x1][24]=1;
        x1=29;y1=24;x2=10;y2=24;k=0;
        for (i=0;i<m;i++)
        {
            cin>>c;
            k++;
            switch (c)
            {
                case 'E':a[x1][y1]=1;x1=x1+1;break;
                case 'W':a[x1][y1]=2;x1=x1-1;break;
                case 'N':a[x1][y1]=3;y1=y1-1;break;
                case 'S':a[x1][y1]=4;y1=y1+1;break;
            }
            switch (a[x2][y2])
            {
                case 1:a[x2][y2]=0;x2=x2+1;break;
                case 2:a[x2][y2]=0;x2=x2-1;break;
                case 3:a[x2][y2]=0;y2=y2-1;break;
                case 4:a[x2][y2]=0;y2=y2+1;break;
            }
            if (x1>=0 && x1<50 && y1>=0 && y1<50)
            {
                if (a[x1][y1]==0)
                {
                    if (i+1==m) cout<<"The worm successfully made all "<<k<<" moves.\n";
                    continue;
                }
                else cout<<"The worm ran into itself on move "<<k<<".\n";
            }
            else cout<<"The worm ran off the board on move "<<k<<".\n";
            for (j=i;j<m-1;j++)
            {
                cin>>c;
                i++;
            }
        }
        cin>>m;
    }
}
