#include <iostream>
#include <stdio.h>
using namespace std;
#define bool int
#define false 0
#define true 1
#define MAXLEN 50
int total;
int type_count;
int lengths[MAXLEN];
int counts[MAXLEN];
int starts[256];
int solution[256];
int stick_length;
bool try_it(
    int length,
    int count,
    bool less
)
{
    int s;
    int l;
    int i, j, k;
    s = length / stick_length;
    if((l = length % stick_length) == 0)
    {
        if(length == total)
            return true;
        starts[s] = count;
        i = solution[starts[s-1]];
        less = false;
    }
    else
    {
        i = less ? solution[count-1] : solution[starts[s-1] + (count - starts[s])];
        l = stick_length - l;
        if(lengths[i] > l)
        {
            do { i--; } while(lengths[i] > l);
            less = true;
        }
    }
    for( ; i >= 0; i--)
    {
        if(!counts[i])
            goto skip;
        l = lengths[i];
        for(j = count - 1, k = i + 1; j >= starts[s]; j--)
        {
            l += lengths[solution[j]];
            while(l > lengths[k])
                k++;
            if(k >= type_count)
                break;
            if(l == lengths[k] && !!counts[k])
                goto skip;
        }
        solution[count] = i;
        counts[i]--;
        if(try_it(length + lengths[i], count+1,    less))
        {
            counts[i]++;
            return true;
        }
        counts[i]++;
skip:
        less = true;
    }

    return false;
}
int failed[1024];
int failed_count;
int main()
{
    int m, l, i, j, found, last;
    for(;;)
    {
        scanf("%d", &m);
        if(!m) break;
        memset(counts, 0, sizeof(counts));
        for(i = 0; i < m; i++)
        {
            scanf("%d", &l);
            counts[l-1]++;
        }
        type_count = 1;
        total = counts[0];
        lengths[0] = 1;
        for(i = 1; i < MAXLEN; i++)
        {
            if(!counts[i])
                continue;
            total += (counts[type_count] = counts[i]) * (lengths[type_count] = i+1);
            type_count++;
        }
        lengths[type_count] = total;
        found = total;
        failed_count = 0;
        last = total / lengths[type_count-1];
        for(i = 2; i <= last; i++)
        {
            if(total % i != 0)
                continue;
            for(j = 0; j < failed_count; j++)
                if(i % failed[j] == 0)
                    break;
            if(j != failed_count)
                continue;
            stick_length = total / i;
            starts[0] = 0;
            solution[0] = type_count-1;
            if(try_it(lengths[type_count-1], 1, true))
            {
                found = total / i;
                continue;
            }
            failed[failed_count++] = i;
        }
        printf("%d\n", found);
    }
    return 0;
}

