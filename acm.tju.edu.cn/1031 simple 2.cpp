#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void PrintVer(int,int,char*);
void PrintHor(int,int,char*);
void PrintNumbers(int,char*);

/*LCD��������*/

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

/* ����������ĸ�м����һ������ �����ƽ��ÿ����ĸռ��n+3�У����һ��Ϊ���*/

/*��ӡ��ֱ�ʻ���n-�ʻ����ȣ�section=1����4��numbers-�����ַ���*/
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

    /*������һ���ַ������û�бʻ���Ҫʹ\0ǰ��2��*/
    line[len-1]='\0';
    /*��ӡn��*/
    for(i=0;i<n;i++)
        printf("%s\n",line);
    free(line);
}

/*��ӡˮƽ�ʻ���n-�ʻ����ȣ�section=0��3��or 6��numbers-�����ַ���*/
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

    /*ע�����һ�����ֺ�������ո��ˣ����Զ�����һ��λ��*/
    line[len-1]='\0';
    /*��ӡ1��*/
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
        /*ÿ��������֮����һ������*/
        printf("\n");
    }
    while(1);
}
