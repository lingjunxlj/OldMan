#include <iostream>
#include <cmath>
using namespace std;
int convert(char *s, int l)
{
    int n = 0;
    for(int i=0; i<l; i++)
    n += (s[i]-'0')*pow((double)10, i);
    return n;
}
int main()
{
    char str[25], n1[8], n2[8], n3[8];
    int l1, l2, l3;
    while(cin >> str)
    {
        l1 = l2 = l3 = 0;
        while(str[l1] != '+')
        n1[l1] = str[l1++];
        n1[l1] = '\0';
        while(str[l1+l2+1] != '=')
        n2[l2] = str[l1+(l2++)+1];
        n2[l2] = '\0';
        while(str[l1+l2+2+l3])
        n3[l3] = str[l1+l2+2+(l3++)];
        n3[l3] = '\0';
        if(convert(n1, l1)+convert(n2, l2)==convert(n3, l3))
        cout<<"True\n";
        else
        cout<<"False\n";
    }
}
