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
int getint() //���getchar������Դ�����������ǳ����ã������������Ч�ʲ��ߵ��㷨
{
    int ret = 0;
    char tmp;
    while (!isdigit(tmp = getchar()));
    do {
        ret = (ret << 3)+(ret << 1) + tmp - '0';
    } while (isdigit(tmp = getchar()));
    return ret;
}
