#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 20001;

int top;
int stack[maxn];

struct node{
       int x, y;
}str[maxn];

bool cmp(node a, node b)
{
     if(a.y != b.y)
            return a.y < b.y;
     else
            return a.x < b.x;
}

int find(int x, int n){
    int low = 0, high = top-1;
    while(low <= high){
         int mid = (low+high) >> 1;
         if(stack[mid] == x){
               while(stack[mid] == stack[mid+1]) mid ++;
               return mid;
         }
         if(stack[mid] > x) high = mid - 1;
         else low = mid + 1;
    }
    return high;
}

int main()
{
     int n;
     while(~scanf("%d", &n))
     {
         for(int i = 0; i < n; ++i)
             scanf("%d %d", &str[i].x, &str[i].y);

         top = 0;
         sort(str, str+n, cmp);
         memset(stack, -1, sizeof(stack));
         stack[0] = str[0].y;
         top = 1;
         for(int i = 1; i < n; i++)
         {
              int p = find(str[i].x, top);
              if(p == -1){
                   stack[top++] = str[i].y;
              }
              else if(p == top-1){
                   stack[p] = str[i].y;
              }
              else{
                  for(int j = p; j < top-1; j++)
                          stack[j] = stack[j+1];
                  stack[top-1] = str[p].y;
              }
         }
         printf("%d\n", top);
     }
     return 0;
}
