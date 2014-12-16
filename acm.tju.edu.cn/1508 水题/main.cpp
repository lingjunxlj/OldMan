#include <iostream>
using namespace std;
int a[51][2];
int main ()
{
    int i, j, k;
    int n, s, m;
    int flag, r;
    cin>>n;
    while(n--)
    {
        cin>>s>>m;
        for(i = 0; i < m ; i++)
            cin>>a[i][0]>>a[i][1];

        flag = 0 ;

        for( i = 0 ; i <= s ; i++)
        {
            for( j = 0 ; j <= s ; j++)
            {

                r = i;

                if(r > s-i)
                    r = s - i;

                if(r > j )
                    r = j;

                if( r > s-j )
                    r = s-j ;

                r = r * r;


                for( k = 0; k < m; k++)
                {
                    if( i == a[k][0] && j == a[k][1] )
                        break;
                    if( r < ( a[k][0]-i ) * ( a[k][0]-i ) + ( a[k][1]-j ) * ( a[k][1]-j ) )
                        break;

                }
                if( k == m)
                {
                    flag = 1;
                    break;
                }
            }
            if( flag == 1)
                break;

        }
        if(flag)
            printf("%d %d\n", i, j);

        else
            printf("poodle\n");
    }
    return 1;
}
