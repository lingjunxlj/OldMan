
#include <cstdio>
#include <cstring>

int num_add(int k)
{
        int num = 2 * k - 1, i, sum = 0;;
        for(i = 2; i < k; i++)
            sum += num / i;
        return sum;
}

int main()
{
         char str[5001];
         int lens, sum;
         int i, j;

         while(scanf("%s", str) != EOF)
         {
             lens = strlen(str);
             sum = 0;

             for(i = 0; i < lens; i++)
             {
                 sum++;
                 for(j = 1; i - j >= 0 && i + j < lens; j++)
                     if(str[i - j] == str[i + j])
                         sum++;
                     else
                         break;
                 for(j = 0; i - j >= 0 && i + j < lens - 1; j++)
                     if(str[i - j] == str[i + j + 1])
                         sum ++;
                     else
                         break;
             }
             printf("%d\n", sum);
         }
         return 0;
}
