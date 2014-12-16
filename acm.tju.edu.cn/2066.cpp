#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int i,n,s;
    char a[100000],b[100000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s %s",a,b);
        if(strlen(a)<strlen(b)) printf("NO BRAINS\n");
        else if(strlen(a)>strlen(b)) printf("MMM BRAINS\n");
        else
        {
            s=strcmp(a,b);
            if(s>=0) printf("MMM BRAINS\n");
           else printf("NO BRAINS\n");
        }
    }
}
