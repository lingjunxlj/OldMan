#include <iostream>
#include <string>
using namespace std;
int add[501];
int main()
{
    int x;
    cin>> x;
    while (x--)
    {
        int n, i, max=0;
        cin>> n;
        memset(add, 0, sizeof(add));
        while (n--)
        {
            int a, b, temp;
            cin>> a>> b;
            if(a > b)
            {
                temp = b;
                b = a;
                a = temp;
            }

            for (i= (a-1)/2;i<= (b-1)/2; i++)
                add[i]++;
        }
        for (i= 0;i< 501;i++)
            if (add[i] > max)
                max = add[i];

        cout<< (max)*10<< endl;
    }
}
