#include <iostream>   
#include <cstdio>   
#include <cstring>   
#include <utility>   
using namespace std;   
int map[5][5] = {{5, -1, -2, -1, -3},   
                 {-1, 5, -3, -2, -4},   
                 {-2, -3, 5, -2, -2},   
                 {-1, -2, -2, 5, -1},   
                 {-3, -4, -2, -1, 0}};   
char gene1[102], gene2[102];   
int dp[102][102];   
  
int main()   
{   
    int C;   
    int len1, len2;   
    scanf("%d", &C);   
    while(C--)   
    {   
        scanf("%d%s", &len1, &gene1);   
        scanf("%d%s", &len2, &gene2);   
        for(int i = 0; i < len1; ++i)   
            switch(gene1[i])   
            {   
                case 'A': gene1[i] = '0'; break;   
                case 'C': gene1[i] = '1'; break;   
                case 'G': gene1[i] = '2'; break;   
                case 'T': gene1[i] = '3'; break;   
            }   
  
        for(int i = 0; i < len2; ++i)   
            switch(gene2[i])   
            {   
                case 'A': gene2[i] = '0'; break;   
                case 'C': gene2[i] = '1'; break;   
                case 'G': gene2[i] = '2'; break;   
                case 'T': gene2[i] = '3'; break;   
            }   
  
        dp[0][0] = 0;   
  
        for(int i = 1; i <= len2; ++i)   
            dp[0][i] = dp[0][i-1] + map[4][gene2[i-1]-'0'];   
  
        for(int i = 1; i <= len1; ++i)   
            dp[i][0] = dp[i-1][0] + map[gene1[i-1]-'0'][4];   
  
        for(int i = 1; i <= len1; ++i)   
            for(int j = 1; j <= len2; ++j)   
                dp[i][j]= max(   
                max(dp[i][j-1]+map[4][gene2[j-1]-'0'],   
                dp[i-1][j]+map[gene1[i-1]-'0'][4]),   
                dp[i-1][j-1]+map[gene1[i-1]-'0'][gene2[j-1]-'0']);   
  
        printf("%d\n", dp[len1][len2]);   
    }   
    return 0;   
}   
