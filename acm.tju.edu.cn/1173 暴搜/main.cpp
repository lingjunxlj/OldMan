#include<cstdio>
const int MAX=0x7fffff;
int m[7][7],N;
int MIN;
void move(int row, int n)
{
    int temp = m[row][n - 1];
    for(int i = n - 1; i >= 1; --i)
    {
        m[row][i] = m[row][i - 1];
    }
    m[row][0] = temp;
}
int DFS(int t, int n)
{
    if(t >= n)
    {
        int max = -1, sum;
        for(int i = 0; i < n; ++i)
        {
            sum = 0;
            for(int j = 0; j < n; ++j)
            {
                sum += m[j][i];
            }
            if(sum > max)
            max = sum;
        }
        if(max < MIN)
        {
            MIN = max;
        }
    }
    else
    {
        for(int i = 0; i < n ; ++i)
        {
            move(t, n);
            DFS(t + 1, n);
        }
    }
}
int main()
{
    int i, j;
    while(scanf("%d", &N) && N != -1)
    {

        for(i = 0; i < N; ++i)
            for(j = 0; j < N; ++j)
                scanf("%d", &m[i][j]);

        MIN = MAX;
        DFS(0, N);
        printf("%d\n", MIN);
    }
    return 0;
}
