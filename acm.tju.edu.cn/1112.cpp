#include<iostream>
using namespace std;

int main()
{
    string digits[100];
    int i = 0,maxLength = 0;
    while (cin >> digits[i]){
          if (digits[i] == "0")
               break;
          else{
               int length = digits[i].length();
               if(length>maxLength)
                    maxLength = digits[i].length();
               i++;
          }
               
    }
    int a[100][100];
    int c[101];
    int carry = 0, sum = 0;
    for (int j = 0; j < 100; j++){
        for (int k = 0; k < 100; k++)
              a[j][k] = 0;
    }
    for (int j = 0; j < 100; j++)
              c[j] = 0;
    for (int j = 0; j < i; j++)
        for(int k = 0, m = digits[j].length()-1; k < digits[j].length(); k++, m--)
                a[j][k] = digits[j][m]-'0';
    for (int j = 0; j < maxLength; j++){
        sum = 0;
        for (int k = 0; k < i; k++)
            sum += a[k][j];
        sum += carry;
        c[j] = sum%10;
        carry = sum/10;
    }
    if ( carry != 0 ){
         c[maxLength] = carry;
         maxLength++;
    }
    int h;
    for (h = maxLength-1; h >= 1; h--)
    {
        if (c[h] == 0)
             continue;
        else
             break;
    }
    for (int j = h; j >= 0; j--)
          cout << c[j];
          cout<<endl;
    return 0;
}
