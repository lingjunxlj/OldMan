#include <cstdio>
#include <cstring>
char str[100], source[100];

double change(char *str)
{
    int i, x = 1, j;
    double now_time = 0;
    for(i = 0; ; i++)
        if(str[i] == ':' )
        break;

    for(j = i - 1; j >= 0; j--)
    {
        now_time += (str[j] - '0') * x;
        x *= 10;
    }
    now_time += ( (str[i + 1] - '0') * 10 + (str[i + 2] - '0') ) / 60.0;
    now_time += ( (str[i + 4] - '0') * 10 + (str[i + 5] - '0') ) / 3600.0;
    return now_time;
}


int main()
{
    double sum = 0, start = 0, now_time, v = 0, v1;
    while(gets(source))
    {
        int i;
        for(i = 0;; i++)
            if(source[i] == 0 || source[i] == ' ')
            break;
        if(source[i] == ' ')
        {
            sscanf(source, "%s %lf", str, &v1);
            now_time = change(str);
            sum += v * (now_time - start);
            start = now_time;
            v = v1;
        }
        else
        {
            sscanf(source, "%s", str);
            now_time = change(str);
            sum += v * (now_time - start);
            start = now_time;
            printf("%s ", str);
            printf("%.2lf km\n", sum);
        }
    }
    return 0;
}
