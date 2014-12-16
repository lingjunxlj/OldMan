/*
1		        1  	1*1		    1	2*1-1
1 1		        2  	1*1+1		2	2*1
1 2 1		    4  	2*2		    3	2*2-1
1 2 2 1		    6  	2*2+2		4	2*2
1 2 3 2 1	    9  	3*3		    5	2*3-1
1 2 3 3 2 1	    12 	3*3+3		6	2*3
*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while (n--)
    {
        int a,b;
        cin>>a>>b;
        int s=b-a;
        int step=0,l=int(sqrt(s));
        if (s==0)
        cout<<0<<endl;
        else
        {

            if(s==l*l)
            printf("%d\n",2*l-1);
            else if(s<=l*l+l)
            printf("%d\n",2*l);
            else
            printf("%d\n",2*(l+1)-1);
        }
    }
}


