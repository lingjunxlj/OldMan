#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int t, money;
    cin>>t;
    while(t--)
    {
        cin>>money;
        if (money == 200 || money == 150)
            cout<<0<<endl;
       else
       {
            if (money < 150)
                cout<<money<<endl;
            else if (money > 150 && money < 200)
                cout<<money - 150<<endl;
            else if (money > 200 && money < 300)
                cout<<money - 200<<endl;
            else
                cout<<money%50<<endl;
       }
    }
}
