#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char a[100],b[100],s[100];
    gets(a);
    gets(b);
    puts(b);
    puts(a);
    while(gets(s))
    {
        for(int i=0;i<strlen(s);i++)
        {
            int f=0;
            for(int j=0;j<strlen(a);j++)
            {
                if(s[i]==a[j])
                {
                    f=1;
                    cout<<b[j];
                }
            }
            if(!f)
            cout<<s[i];
        }
        cout<<endl;
    }
    return 0;
}

