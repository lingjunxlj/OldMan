#include <iostream>
using namespace std;
int main()
{
    double k,s;
    while (cin>>k)
    {
        int i;
        s=0;
        for (i=1;;i++)
        {
            s+=(k/100)/i;
            if (s>=1)
            {
                cout<<i<<endl;
                break;
            }
        }
    }
}
