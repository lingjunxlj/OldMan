#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;
int Get(string str)
{
    int sum = 0;
    int i, len=str.length(), k=0;
    for(i = len - 1; i >= 0; i--)
    {
        sum += (int)( (str[i] - '0') * pow(10.0, k++) );
    }
    return sum;
}
int main()
{
    string str;
    int n, i, len;
    while(cin>>str)
    {
        cin>>n;
        len = str.length();
        int num = 0;
        for(i = 0; i < len; i++)
            if(str[i] == '0')
                num++;
            int ss = 0 , kk;
        int j = len - 1, k;
        int  t = len - num;
        bool mark = false;
        for(i = 0; i < n; i++)
        {
            if(num == 0)
            {
                ss = i;
                mark = true;
                break;
            }
            char ch = str.at(j);
            str.erase(j);
            if(ch != '0')
                str = ch + str;
            else
            {
                j--;
                num--;
            }
        }
        if (!mark)
        printf("%d\n", Get(str));
        else
        {
          kk = n - ss;
          ss = kk % t;
          for (i = 1 ; i <=ss ; ++ i)
          {
              char temp = str.at(t-1);
              str.erase(t-1);
              str = temp + str;
          }
          printf("%d\n", Get(str));
        }
    }
    return 0;
}
