#include <iostream>
using namespace std;
int main()
{
    int x;
    cin>>x;
    while (x--)
    {
        int n;
        cin>>n;

        int i, j, k;

        k = n; i = 2; j = 1;

        while (k != 1)
        {
            if (k % i == 0)
            j *= i;

            while (k % i == 0)
            k /= i;

            i++;
        }
        i = 1;
        k = 2;
        while (j * i < n)
        {
            k++;
            i++;
        }
        cout<<k<<endl;
    }
}
