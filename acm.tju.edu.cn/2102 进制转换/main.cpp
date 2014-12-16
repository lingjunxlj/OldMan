#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    int R, C, len, i, j;
    char str[31];
    while (1)
    {
        cin>>str;
        len = strlen(str);

        R = C = 0;
        for (i = 1; str[i] != 'C'; i++)
        {
            R *= 10;
            R += str[i] - '0';
        }
        for (i++; i < len; i++)
        {
            C *= 10;
            C += str[i] - '0';
        }
        if (C == 0 && R == 0)
            return 0;
        i = 0;
        memset (str, 0, sizeof(str));

        while(C)
        {

            str[i] = C % 26;
            if(!str[i])
            {
                str[i] = 26;
                C--;
            }
            str[i] += ('A' - 1);
            C /= 26;
            i++;
        }
        reverse(str, str + i);
        //_strrev(str);
        printf("%s%d\n", str, R);
       }
}
