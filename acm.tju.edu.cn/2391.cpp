#include<stdio.h>
#include<string.h>
char a[2][101];
int main()
{
    int i, j, l;
    int n[2][26]={0};
    scanf("%s", a);
    scanf("%s", a+1);
    l = strlen(a[0]);
    for(i=0; i<l; i++)
    {
        n[0][a[0][i]-'A']++;
        n[1][a[1][i]-'A']++;
    }
    for(i=0; i<26; i++)
    {
        for(j=0; j<26; j++)
        if(n[0][i] == n[1][j])
        {
            n[1][j] = 0;
            break;
        }
        if(j == 26)
        {
            printf("NO\n");
            break;
        }
    }
    if(i == 26)
        printf("YES\n");
    return 0;
}
