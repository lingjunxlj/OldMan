#include <iostream>
using namespace std;
int main()
{
    int carry, n, j, a[800], digit, temp, i, t, num, x;
    cin >> t;
    while(t--)
    {
        cin >> n >> num;
        digit = 1;
        a[0] = 1;
        x = 0;
        for(i = 2; i <= n; i++)
        {
            carry = 0;
            for(j = 1; j <= digit; j++)
            {
                temp = a[j - 1] * i + carry;
                a[j - 1] = temp % 10;
                carry = temp / 10;
            }
            while(carry)
            {
                //if (carry%10 == num)
                //x ++;
                a[++digit - 1] = carry % 10;
                carry /= 10;
            }
        }
        temp = 0;
        for(i = 0; i < digit; i++)
        {
            if(a[i] == num)
            temp++;
        }

        cout << temp << endl;
    }
    return 0;
}
