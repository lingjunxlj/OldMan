#include<cstdio>
#include<cmath>
//Ƥ�˶���
//������������������㣨�������θ�㣩�ļ򵥶���Σ�Ƥ�˶���˵���������A���ڲ������Ŀi�����ϸ����Ŀb�Ĺ�ϵ��A = i + b/2 - 1��
struct point
{
    double x,y;
}p,q;

int gcd(int a,int b)
{
    int t;
    if(a > b)
    {
        t = a;
        a = b;
        b = t;
    }
    if(a == 0)
    return b;
    while(a != 0)
    {
        t = b % a;
        b = a;
        a = t;
    }
    return b;
}
int main()
{
    int n, i, x1, y1, g;
    double s, m;
    scanf("%d", &g);
    for(int k = 1;k <= g; k++)
    {
        scanf("%d", &n);
        s = m = p.x = p.y = 0;
        for(i = 1;i <= n; i++)
        {
            scanf("%d %d", &x1, &y1);
            q.x = p.x + x1;
            q.y = p.y + y1;
            s += ( p.x * q.y ) - ( q.x * p.y);
            m += gcd( (int)fabs(x1), (int)fabs(y1) );
           // printf("GCD ==  %d   \n",gcd( (int)fabs(x1), (int)fabs(y1) ));
            p = q;
        }
        printf("Scenario #%d:\n%d %0.0f %0.1f\n\n", k, int(0.5*fabs(s)+1-m/2), m, fabs(s)*0.5);
    }
}
