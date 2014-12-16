#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    double vul, d, test;
    int add, i;
    while( scanf("%lf %lf", &vul, &d) != EOF )
    {
        add = vul / d;
        test = add;
        if(test != vul/d)
            add++;
        for(i = 1; vul > 0; i++)
            vul -= i * d;

        printf("%d\n", i - 2 + add);
    }
}
