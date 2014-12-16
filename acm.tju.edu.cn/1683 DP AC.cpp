#include<stdio.h>
#include<string.h>
#define max(a,b) (a>b?a:b)
char a[1005],b[1005];
int best[1005][1005];
void process()
{
    int lena,lenb,i,j;
    lena=strlen(&a[1]);lenb=strlen(&b[1]);
    for(i=0;i<=lena;i++)
        best[i][0]=0;
    for(j=0;j<=lenb;j++)
        best[0][j]=0;
    for(i=1;i<=lena;i++){
        for(j=1;j<=lenb;j++){
            if(a[i]==b[j])
                best[i][j]=best[i-1][j-1]+1;
            else
                best[i][j]=max(best[i-1][j],best[i][j-1]);
        }
    }
    printf("%d\n",best[lena][lenb]);

}
int main()
{
    int i;
    while(scanf("%s %s",&a[1],&b[1])!=EOF){
        process();
    }
    return 0;
}
