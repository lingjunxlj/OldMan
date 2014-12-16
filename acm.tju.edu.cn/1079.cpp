

/*http://hi.baidu.com/fandywang_jlu/blog/item/a04c8509382286256b60fbf2.html*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const int MAX_LENGTH = 1000;

int main(void)
{
int      len, i, j, temp, num, index;/*表示数组dest下标*/
char      src[MAX_LENGTH];

while(scanf("%s",src) != EOF)
{
      char      dest[MAX_LENGTH] = {'0'};/*存放转化后的十进制数（无0.）*/
      for(i = strlen(src)-1, index = 0; i > 1; i--, index = j)
      {

       /*a1----an-1*/
       num = src[i]-'0';
       for(j=0; j < index; j++)
       {
        temp = num*10 + dest[j]-'0';
        dest[j] = temp/8+'0';
        num = temp%8;
       }

        /*a1------an*/
       while(num)
       {
        num *= 10;
        dest[j++] = num/8+'0';
        num %= 8;
       }
      }
      dest[j] = '\0';//

      printf("%s [8] = 0.%s [10]\n", src, dest);
}
system("pause");
return 0;
}
