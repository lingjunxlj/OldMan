#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while (n--)
    {
        int year, month, day;
        cin>>year>>month>>day;
        if (month == 9 && day == 30)
        {
            printf("YES\n");
            continue;
        }
        if (month == 11 && day == 30)
        {
            printf("YES\n");
            continue;
        }
        if ((month + day) % 2 == 1)
            printf("NO\n");
        else
            printf("YES\n");
    }
}
