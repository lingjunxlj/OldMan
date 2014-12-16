#include <iostream>
#include <cstdlib>
using namespace std;
long long a[2000];
int main()
{
    long long z,i,m,l,y=0;
    while (cin>>z>>i>>m>>l&&z!=0&&i!=0&&m!=0&&l!=0)
    {
        y++;
        long long t,s,j,k;
        j=0;t=0;
        while (1)
        {
            a[j]=(z*l+i)%m;
            l=a[j];
            j++;
            for (k=0;k<j-1;k++)
            if (a[k]==l)
            t=1;
            if (t==1)
            break;
        }
        cout <<"case "<<y<<": "<<j-1<<endl;
    }
}
