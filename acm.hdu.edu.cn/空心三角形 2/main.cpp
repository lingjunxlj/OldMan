#include<iostream>
using namespace std;
int main()
{
    char c;
    int n, i, j, k = 0;
    while(cin>>c, c != '@')
    {
        cin>>n;
        if(k != 0)
            cout<<endl;
        for(i = 0; i < n - 1; i++)
        {
            for(j = 1; j < n + i; j++)
            {
                if((n - j) % n == i)
                    cout<<c;
                else
                    cout<<" ";
            }
            cout<<c<<endl;
        }
        n = n * 2 - 1;
        while(n--)
            cout<<c;
        cout<<endl;
        k++;
    }
    return 0;
}
