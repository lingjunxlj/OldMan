#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
    int i, j, n, m;
    double len1,len2;
    double step,sum,step1;
    while (cin>>n>>m)
    {
        step = 10000.0/( (double)(n + m) );
        step1 = 10000.0/( (double)n );
        len1 = sum = 0 ;
        len2 = step1 ;
        j = 1;
        for(i = 1; i < n + m ; i++)
        {
            len1 += step;
            if(i%n == 0 && i%(n+m)==0)
            {
                len2 += step1;
                continue;
            }

            if( len1 > len2)
            {
                sum += min( (len1-len2) , (len2-(len1-step)) );
                len2 += step1 ;
            }
        }
        printf("%.4lf\n",sum);
     }
}
