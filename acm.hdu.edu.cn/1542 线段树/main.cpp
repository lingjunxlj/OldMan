/*

                            解决ZOJ1128的线段树模板

1757411 2006-04-12 19:51:35 Accepted 1128 C++ 00:00.00 484K 极光炫影

                             Author : JGShining
                             Date : 2006-04-12
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
using namespace std;

typedef struct ITREE_NODE
{
     ITREE_NODE *pLChild, *pRChild;
     double left, right;         // 左端点，右端点
     double measure;             // 测度
     int count;                  // 覆盖计数器
     int lines;                  // 独立线段数
     int lbound, rbound;         // 覆盖左、右顶点的线段数目
} *PITREE_NODE;

inline void safe_add(int& v, int value)
{
     v += value;
     if(v < 0) v = 0;
}

void itree_splite(const double *pList, PITREE_NODE pParent,
                    const int iLeft, const int iRight)
{
     assert(pList);
     if(iRight - iLeft <= 1) return;
     int iMid = (iLeft + iRight) >> 1;
     pParent->pLChild = new ITREE_NODE;
     pParent->pRChild = new ITREE_NODE;
     memset(pParent->pLChild, 0, sizeof(ITREE_NODE));
     memset(pParent->pRChild, 0, sizeof(ITREE_NODE));
     pParent->pLChild->left = pList[iLeft];
     pParent->pLChild->right = pList[iMid];
     pParent->pRChild->left = pList[iMid];
     pParent->pRChild->right = pList[iRight];
     itree_splite(pList, pParent->pLChild, iLeft, iMid);
     itree_splite(pList, pParent->pRChild, iMid, iRight);
}

PITREE_NODE itree_generate(const double *pList, const int iListCount)
{
     assert(pList);
     PITREE_NODE pRoot = new ITREE_NODE;
     memset(pRoot, 0, sizeof(ITREE_NODE));
     pRoot->left = pList[0];
     pRoot->right = pList[iListCount - 1];
     itree_splite(pList, pRoot, 0, iListCount - 1);
     return pRoot;
}

void itree_destroy(PITREE_NODE pParent)
{
     if(pParent == NULL) return;
     if(pParent->pLChild) itree_destroy(pParent->pLChild);
     if(pParent->pRChild) itree_destroy(pParent->pRChild);
     delete pParent;
}

inline void itree_measure(PITREE_NODE pNode)
{
     if(pNode->count > 0)
         pNode->measure = pNode->right - pNode->left;
     else if(pNode->pLChild && pNode->pRChild)
         pNode->measure = pNode->pLChild->measure + pNode->pRChild->measure;
     else pNode->measure = 0;
}

inline void itree_lines(PITREE_NODE pNode)
{
     if(pNode->count > 0)
         pNode->lines = 1;
     else if(pNode->pLChild && pNode->pRChild)
     {
         if(pNode->pLChild->rbound && pNode->pRChild->lbound)
              pNode->lines = pNode->pLChild->lines + pNode->lines - 1;
         else
              pNode->lines = pNode->pLChild->lines + pNode->lines;
     }
     else pNode->lines = 0;
}

// 插入的时候value = 1, 删除的时候value = -1
void itree_update(PITREE_NODE pParent, const double left, const double right, int value)
{
     assert(pParent);
     if(pParent->left == left && pParent->right == right)
     {
         safe_add(pParent->count, value);
         safe_add(pParent->lbound, value);
         safe_add(pParent->rbound, value);
         itree_measure(pParent);
         itree_lines(pParent);
     }
     else
     {
         if(pParent->pLChild->right > left)
         {
              if(pParent->pLChild->right >= right)
                   itree_update(pParent->pLChild, left, right, value);
              else
              {
                   itree_update(pParent->pLChild, left, pParent->pLChild->right, value);
                   itree_update(pParent->pRChild, pParent->pRChild->left, right, value);
              }
         }
         else itree_update(pParent->pRChild, left, right, value);
         itree_measure(pParent);
         itree_lines(pParent);
         if(left == pParent->left) safe_add(pParent->lbound, value);
         if(right == pParent->right) safe_add(pParent->rbound, value);
     }
}

void itree_insert(PITREE_NODE pParent, const double left, const double right)
{
     itree_update(pParent, left, right, 1);
}

void itree_delete(PITREE_NODE pParent, const double left, const double right)
{
     itree_update(pParent, left, right, -1);
}

struct EVENT
{
     double x, y1, y2;
     int type;
};

bool cmp(const EVENT& a, const EVENT& b)
{
     return a.x < b.x;
}

PITREE_NODE pRoot;
EVENT env[200];
double Y[200];
double tsize = 0.0;

int main()
{
     double x1, x2, y1, y2;
     int i, n, n2, cas = 0;
     while(scanf("%d", &n) == 1 && n)
     {
         cas++;
         n2 = n << 1;
         for(i = 0; i < n2; i += 2)
         {
              scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
              env[i].x = x1;
              env[i].y1 = y1;
              env[i].y2 = y2;
              env[i].type = 1;
              env[i + 1].x = x2;
              env[i + 1].y1 = y1;
              env[i + 1].y2 = y2;
              env[i + 1].type = -1;
              Y[i] = y1;
              Y[i + 1] = y2;
         }
         sort(env, env + n2, cmp);
         sort(Y, Y + n2);
         pRoot = itree_generate(Y, n2);
         for(i = 0; i < n2; ++i)
         {
              if(i > 0)
                   tsize += pRoot->measure * (env[i].x - env[i - 1].x);
              else
                   tsize = 0.0;
              itree_update(pRoot, env[i].y1, env[i].y2, env[i].type);
         }
         itree_destroy(pRoot);
         printf("Test case #%d\nTotal explored area: %.2lf\n\n", cas, tsize);
     }
     return 0;
}
