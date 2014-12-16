#include<iostream>
#include<string>
using namespace std;
int main()
{
    char s[27]="01230120022455012623010202";
    char str[21];
    while(cin>>str){
        int a,temp=0;
        int i;
        int len=strlen(str);
        for(i=0;i<len;i++){
            a=s[str[i]-'A']-'0';
            if(a&&a!=temp)
                printf ("%d",a);
            temp=a;
        }
        printf("\n");
    }
    return 0;
}
