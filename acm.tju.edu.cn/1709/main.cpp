#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int t, x=0;
    cin>>t;
    while (t--)
    {
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        x++;
        printf("Scenario #%d:\n", x);

        if ((a+b+c+d)%2 == 1)
        printf("%d\n", 1);
        else
        printf("%d\n", 0);
        //if (t != 0)
        printf("\n");


    }
}
