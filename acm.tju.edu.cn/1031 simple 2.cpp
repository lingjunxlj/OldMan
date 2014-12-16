#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void PrintVer(int,int,char*);
void PrintHor(int,int,char*);
void PrintNumbers(int,char*);

/*LCD的字型码*/

/*    -0-
    1       2
       -3-
    4       5
       -6-     
*/

int LCDCODES[10][7]=
{
    {1,1,1,0,1,1,1},/*0*/
    {0,0,1,0,0,1,0},/*1*/
    {1,0,1,1,1,0,1},/*2*/
    {1,0,1,1,0,1,1},/*3*/
    {0,1,1,1,0,1,0},/*4*/
    {1,1,0,1,0,1,1},/*5*/
    {1,1,0,1,1,1,1},/*6*/
    {1,0,1,0,0,1,0},/*7*/
    {1,1,1,1,1,1,1},/*8*/
    {1,1,1,1,0,1,1} /*9*/
};

char c_ver='|';
char c_hor='-';

/* 两个相邻字母中间隔了一个空列 ，因此平均每个字母占据n+3列，最后一列为间隔*/

/*打印竖直笔画，n-笔画长度，section=1或者4，numbers-数字字符串*/
void PrintVer(int n,int section,char *numbers)
{
    char *line;
    int i,len=(n+3)*strlen(numbers);
    line=(char*)malloc(len+1);
    if(line==NULL)
        return;
    memset(line,' ',len);
    for(i=0;i<strlen(numbers);i++)
    {
        if(LCDCODES[*(numbers+i)-'0'][section])
            *(line+(n+3)*i)=c_ver;
        if(LCDCODES[*(numbers+i)-'0'][section+1])
            *(line+(n+3)*i+(n+1))=c_ver;
    }

    /*检查最后一个字符，如果没有笔画，要使\0前移2格！*/
    line[len-1]='\0';
    /*打印n行*/
    for(i=0;i<n;i++)
        printf("%s\n",line);
    free(line);
}

/*打印水平笔画，n-笔画长度，section=0，3，or 6，numbers-数字字符串*/
void PrintHor(int n,int section,char *numbers)
{
    char *line;
    int i,len=(n+3)*strlen(numbers);
    line=(char*)malloc(len+1);
    if(line==NULL)
        return;
    memset(line,' ',len);

    for(i=0;i<strlen(numbers);i++)
    {
        if(LCDCODES[*(numbers+i)-'0'][section])
            memset((line+(n+3)*i+1),c_hor,n);
    }

    /*注意最后一个数字后面无需空格了！所以多缩进一个位置*/
    line[len-1]='\0';
    /*打印1行*/
    printf("%s\n",line);
    free(line);
}

/* Print A set of Numbers : "23456" e.g. */
void PrintNumbers(int n,char *numbers)
{
    PrintHor(n,0,numbers);    /*  ----    */
    PrintVer(n,1,numbers);    /* |     |   */
    PrintHor(n,3,numbers);    /*  ----    */
    PrintVer(n,4,numbers);    /* |     |   */
    PrintHor(n,6,numbers);    /*  ----    */
}

int main()
{
    char line[20];
    char *str1,*numbers,*delim=" ";
    int n;

    do
    {
        gets(line);
        str1=strtok(line,delim);
        numbers=strtok(NULL,delim);
        n=atoi(str1);
        if(n<=0)
            break;

        PrintNumbers(n,numbers);
        /*每两行数字之间有一个空行*/
        printf("\n");
    }
    while(1);
}
