#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    char words[1000][17];
    long points[1000];
    long point=0;
    int m,n;
    cin>>m>>n;
    for (int i1=0;i1<=m-1;i1++)
    cin>>words[i1]>>points[i1];
    for (int i=0;i<=n-1;i++)
    {
        char tmp='\0';char tmpword[17]="";
        for (cin >>tmpword;tmpword[0]!='.';cin>>tmpword)
        {
            for (int k=0;k<=m-1;k++)
            {
                if (strcmp(tmpword,words[k])==0)
                {
                    point+=points[k];
                    break;
                }
            }
        }
        cout <<point <<endl;point=0;
    }
}
