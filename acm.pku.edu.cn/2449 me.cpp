#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cmath>
#incude <cstdlib>
using namespace std;
int getint() //这个getchar的输入对大数据量输入非常有用，甚至可以挽救效率不高的算法
{
    int ret = 0;
    char tmp;
    while (!isdigit(tmp = getchar()));
    do {
        ret = (ret << 3)+(ret << 1) + tmp - '0';
    } while (isdigit(tmp = getchar()));
    return ret;
}
