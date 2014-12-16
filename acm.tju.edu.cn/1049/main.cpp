#include <cstdio>
struct rect
{
    int x1;
    int x2;
    int y1;
    int y2;
}rec[5001];
bool flag(int i,int j){

    if ((rec[i].x1>=rec[j].x1)&&(rec[i].x2<=rec[j].x2)&&(rec[i].y1>=rec[j].y1)&&(rec[i].y2<=rec[j].y2))
    return true;
    else
    return false;
}
int main(){

    int i,j,n;

    while (scanf("%d",&n)!=EOF){
        int sum=0;

        for (i=1;i<=n;i++)
            scanf("%d %d %d %d",&rec[i].x1,&rec[i].x2,&rec[i].y1,&rec[i].y2);

        for (i=1;i<=n;i++)
            for (j=1;j<=n;j++){
                if (i!=j&&flag(i,j)){
                    sum++;
                    break;
                }
            }
        printf("%d\n",sum);
    }
}
