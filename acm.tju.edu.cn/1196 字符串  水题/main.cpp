#include<iostream>
#include<string>
using namespace std;
char str[100], url[1000][100];
int main() {
    strcpy(url[0],"http://www.acm.org/");
    int g=0,b=0;
    while (cin>>str)
    {
        if (str[0]=='V')
        {
            cin>>str;
            cout<<str<< endl;
            g++;
            strcpy(url[g],str);
            b=g;
        }
        else if (str[0]=='B')
        {
            if (g>=1)
            {
                g--;
                cout<<url[g]<<endl;
            }
            else
            {
                cout<<"Ignored"<<endl;
                g=0;
            }
        }
        else if (str[0]=='F')
        {
            g++;
            if (g<=b)
            {
                cout<<url[g]<< endl;
            }
            else
            {
                cout<<"Ignored"<<endl;
                g=b;
            }
        }
        else if (str[0]=='Q')
        {
            break;
        }
    }
    return 0;
}
