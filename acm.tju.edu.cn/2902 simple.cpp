#include <cstdio>
#include <string>
#include <set>
using namespace std;
const int MAX = 100;
char str[MAX];
string sstr;
int len;
set<string> Jihe;
bool check(int l) 
{
    int i;
    for (i=0;i<=len-l;i++) 
    {
        int s=i;
        int t=i+l-1;
        bool flag=true;
        while (s<t) 
        {
            if (str[s]!=str[t]) 
            {
                flag=false;
                break;
            }
            s++;
            t--;
        }
        if (flag) 
        return true;
    }
    return false;
}
void getp(int l) 
{
    int i;
    for (i=0;i<=len-l;i++) 
    {
        int s=i;
        int t=i+l-1;
        bool flag=true;
        while (s<t) 
        {
            if (str[s]!=str[t]) 
            {
                flag=false;
                break;
            }
            s++;
            t--;
        }
        if (flag) 
        Jihe.insert(sstr.substr(s,l));
    }
}
int main() 
{
    int i,j;
    while (gets(str)) 
    {
        len = strlen(str);
        sstr = str;
        for (i=len;i>0;i--) 
        {
            if (check(i)) 
            break;
        }
        Jihe.clear();
        getp(i);
        printf("%d %d\n", i, Jihe.size());
    }
}
