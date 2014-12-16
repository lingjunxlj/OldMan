#include <cstdio>
#include <cstring>
const int INF =  0x7ff;
int a, b, n, num[201], count[201], flag[201], map[201][201];
void dijkstra(){
    for (int i = 1; i <= n; i++)
        count[i] = map[a][i];
    flag[a] = 0;count[a] = 0;
    int min, v;
    for (int i = 1; i < n; i++){
        min = INF;
        for (int j = 1; j <= n; j++){
            if (flag[j] && min > count[j]){
                v = j;
                min = count[j];
            }
        }
        flag[v] = 0;
        for (int j = 1; j <= n; j++)
            if (flag[j] && count[j] > map[v][j] + count[v])
                count[j] = map[v][j] + count[v];

    }
    if (count[b] != INF)
        printf("%d\n", count[b]);
    else
        printf("-1\n");
}
int main(){
    while(scanf("%d", &n), n){
        scanf("%d%d", &a, &b);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                map[i][j] = 0X7ff;
        for (int i = 1; i <= n; i++){
            scanf("%d", &num[i]);
            if (i - num[i] >= 1){
                  map[i][i - num[i]] = 1;
                  flag[i] = flag[i - num[i]] = 1;
            }
            if (i + num[i] <= n){
                map[i][i + num[i]] = 1;
                flag[i] = flag[i + num[i]] = 1;
            }
        }
        dijkstra();
    }
}
