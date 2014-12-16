/****************************************
  Name: 3D Convex Hull
  Author: Isun
  Date: 1-10-10 17:20
  Description: 求三维空间点集凸包 ——增量法 O(n^2)
*****************************************/

#include<stdio.h>
#include<math.h>
#include<algorithm>
#define eps 1e-8
#define MAXV 305
using namespace std;

//三维点
struct pt{
	double x, y, z;
	pt(){}
	pt(double _x, double _y, double _z): x(_x), y(_y), z(_z){}
	pt operator - (const pt p1){return pt(x - p1.x, y - p1.y, z - p1.z);}
	pt operator * (pt p){return pt(y*p.z-z*p.y, z*p.x-x*p.z, x*p.y-y*p.x);}		//叉乘
	double operator ^ (pt p){return x*p.x+y*p.y+z*p.z;}							//点乘
};
double vlen1(pt a){return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);}
double area1(pt a, pt b, pt c){return vlen1((b-a)*(c-a));}
struct _3DCH{
	struct fac{
		int a, b, c;	//表示凸包一个面上三个点的编号
		bool ok;		//表示该面是否属于最终凸包中的面
	};

	int n;	//初始点数
	pt P[MAXV];	//初始点

	int cnt;	//凸包表面的三角形数
	fac F[MAXV*8]; //凸包表面的三角形

	int to[MAXV][MAXV];

	double vlen(pt a){return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);}	//向量长度
	double area(pt a, pt b, pt c){return vlen((b-a)*(c-a));}	//三角形面积*2
	double volume(pt a, pt b, pt c, pt d){return (b-a)*(c-a)^(d-a);}	//四面体有向体积*6

	//正：点在面同向
	double ptof(pt &p, fac &f){
		pt m = P[f.b]-P[f.a], n = P[f.c]-P[f.a], t = p-P[f.a];
		return (m * n) ^ t;
	}

	void deal(int p, int a, int b){
		int f = to[a][b];
		fac add;
		if (F[f].ok){
			if (ptof(P[p], F[f]) > eps)
				dfs(p, f);
			else{
				add.a = b, add.b = a, add.c = p, add.ok = 1;
				to[p][b] = to[a][p] = to[b][a] = cnt;
				F[cnt++] = add;
			}
		}
	}

	void dfs(int p, int cur){
		F[cur].ok = 0;
		deal(p, F[cur].b, F[cur].a);
		deal(p, F[cur].c, F[cur].b);
		deal(p, F[cur].a, F[cur].c);
	}

	bool same(int s, int t){
		pt &a = P[F[s].a], &b = P[F[s].b], &c = P[F[s].c];
		return fabs(volume(a, b, c, P[F[t].a])) < eps && fabs(volume(a, b, c, P[F[t].b])) < eps && fabs(volume(a, b, c, P[F[t].c])) < eps;
	}

	//构建三维凸包
	void construct(){
		cnt = 0;
		if (n < 4)
			return;

		fac add;
		for (int i = 0; i < 4; i++){
			add.a = (i+1)%4, add.b = (i+2)%4, add.c = (i+3)%4, add.ok = 1;
			if (ptof(P[i], add) > 0)
				swap(add.b, add.c);
			to[add.a][add.b] = to[add.b][add.c] = to[add.c][add.a] = cnt;
			F[cnt++] = add;
		}

		for (int i = 4; i < n; i++){
			for (int j = 0; j < cnt; j++){
				if (F[j].ok && ptof(P[i], F[j]) > eps){
					dfs(i, j);
					break;
				}
			}
		}
		int tmp = cnt;
		cnt = 0;
		for (int i = 0; i < tmp; i++){
			if (F[i].ok){
				F[cnt++] = F[i];
			}
		}
	}

	//表面积
	double area(){
		double ret = 0.0;
		for (int i = 0; i < cnt; i++){
			ret += area(P[F[i].a], P[F[i].b], P[F[i].c]);
		}
		return ret / 2.0;
	}

	//体积
	double volume(){
		pt O(0, 0, 0);
		double ret = 0.0;
		for (int i = 0; i < cnt; i++){
			ret += volume(O, P[F[i].a], P[F[i].b], P[F[i].c]);
		}
		return fabs(ret / 6.0);
	}

	//表面三角形数
	int facetCnt_tri(){
		return cnt;
	}

	//表面多边形数
	int facetCnt(){
		int ans = 0;
		for (int i = 0; i < cnt; i++){
			bool nb = 1;
			for (int j = 0; j < i; j++){
				if (same(i, j)){
					nb = 0;
					break;
				}
			}
			ans += nb;
		}
		return ans;
	}
};

	//内有大数组，不易放在函数内
_3DCH hull;
int main()
{

	while (scanf("%d", &hull.n) != EOF)
	{


		for (int i = 0; i < hull.n; i++)
			scanf("%lf%lf%lf", &hull.P[i].x, &hull.P[i].y, &hull.P[i].z);

        if ( hull.n <=2 )
		{
            printf("0.000\n");
            continue;
        }
        if ( hull.n == 3 ){

            printf("%.3lf\n",area1(hull.P[0],hull.P[1],hull.P[2])*0.5 );
            continue;
        }
		hull.construct();
		printf("%.3lf\n", hull.area());
	}
	return 0;
}

