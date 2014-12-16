#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct node
{
    int x;
    int y;
    int now;

}point[100011], point1[100011];
int flag[100011];
bool cmp(node a , node b)
{
    return a.x < b.x;

}
bool cmp1(node a , node b)
{
    return a.y < b.y;

}
int searchx(node array[], int n, int v)
{
    int left, right, middle;

    left = -1, right = n;

    while (left + 1 != right)
    {
        middle = left + (right - left) / 2;

        if (array[middle].x < v)
        {
            left = middle;
        }
        else
        {
            right = middle;
        }
    }

    if (right >= n || array[right].x != v)
    {
        right = -1;
    }

    return right;
}
int searchy(node array[], int n, int v)
{
    int left, right, middle;

    left = -1, right = n;

    while (left + 1 != right)
    {
        middle = left + (right - left) / 2;

        if (array[middle].y < v)
        {
            left = middle;
        }
        else
        {
            right = middle;
        }
    }

    if (right >= n || array[right].y != v)
    {
        right = -1;
    }

    return right;
}
int main()
{
   int n, m, c;
   int d;
   while(scanf("%d %d", &n, &m) != EOF)
   {
        if (n == 0 && m == 0)
            break;
        memset(flag, 0, sizeof(flag));
        for (int i = 0 ; i < n; i++)
        {

            scanf("%d %d", &point[i].x , &point[i].y);
            flag[i] = 0;
            point[i].now = i;
            point1[i].x = point[i].x;
            point1[i].y = point[i].y;
            point1[i].now = i;

        }
        //for (int i = 0; i < n; i++)
            //printf("-%d %d\n", point[i].x, point[i].y);
        sort(point, point + n, cmp);
        sort(point1, point1 + n, cmp1);
        //for (int i = 0; i < n; i++)
            //printf("--%d %d\n", point1[i].x, point1[i].y);
        while(m--)
        {
            scanf("%d %d", &c, &d);
            //cout<<"c == "<<c<<endl;
            if (c == 0)
            {
                int temp = 0, ans = 0;;
                //for (int i = 0 ; i < n; i++)
                    //if (d == point[i].x)
                    //{
                        //temp == i;
                        //break;
                    //}
                temp = searchx(point, n, d);
                //cout<<temp<<endl;

                while(1)
                {
                    if (d == point[temp].x && flag[point[temp].now] == 0)
                    {
                        ans++;
                        flag[point[temp].now] = 1;
                    }

                    temp++;
                    if (point[temp].x != d)
                        break;
                }
                printf("%d\n", ans);
            }
            else
            {
                int temp = 0, ans = 0;;
                //for (int i = 0 ; i < n; i++)
                    //if (d == point[i].y)
                    //{
                        //temp == i;
                       // break;
                   // }
                   temp = searchy(point1, n, d);
                   //cout<<temp<<endl;
                   //cout<<flag[point1[temp].now]<<endl;
                while(1)
                {
                    if (d == point1[temp].y && flag[point1[temp].now] == 0)
                    {
                        //printf("%d %d\n", point1[temp].x, point1[temp].y);
                        ans++;
                        flag[point1[temp].now] = 1;
                    }

                    temp++;
                    if (point1[temp].y != d)
                        break;
                }
                printf("%d\n", ans);
            }

        }
        printf("\n");

   }
}
