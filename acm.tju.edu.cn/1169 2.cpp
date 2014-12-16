#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


int main()
{
    int n,row,col,a,b;
	int arr[100][100];
    cin>>n;
    while ( n)
    {
        
            for(row=0;row<n;row++)
            {
                for(col=0;col<n;col++)
                    cin>>arr[row][col];
            }
        
    
            int m=0,a,b,total,p=0;
            for( row=0; row < n&&m<2 ;row++ )
            {
                total=0;
                for(col=0;col<n;col++)
                    total += arr[row][col];
                if ( total%2 != 0 )
                {
                    a=row+1;
                    m++;
                }
            }
            for( col=0; col < n && p < 2;col ++ )
            {
                total = 0;
                for(row=0;row<n;row++)            
                     total += arr[row][col];
                if ( total % 2 != 0)
                {
                    b = col + 1;
                    p++;
                }
            }
        
            if(m ==2||p==2)
              cout<<"Corrupt" << endl;
            else if(m ==1&&p==1)
                cout<<"Change bit ("<<a<<","<<b<<")"<<endl;
            else if(m ==0&&p==0)
              cout<<"OK" << endl;
            cin >> n;
        
    }
    return 0;
}
