#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<cmath>
using namespace std;
#define N 505
const double eps = 1e-9;
int sgn(const double &x) {
    return (x > eps) - (x < -eps);
}
struct point {
    double x, y, z;
    point() {}
    point(const double &_x, const double &_y, const double &_z) : x(_x), y(_y), z(_z) {}
    point operator +(const point &b) const {
        return point(x + b.x, y + b.y, z + b.z);
    }
    point operator -(const point &b) const {
        return point(x - b.x, y - b.y, z - b.z);
    }
    point operator *(const double &t) const {
        return point(x * t, y * t, z * t);
    }
    point operator /(const double &t) const {
        return point(x / t, y / t, z / t);
    }
    bool operator <(const point &b) const {
        return sgn(x - b.x) < 0 ||(sgn(x - b.x) == 0 && (sgn(y - b.y) < 0 ||(sgn(y - b.y) == 0 && sgn(z - b.z) < 0)));
    }
    bool operator ==(const point &b) const {
        return sgn(x - b.x) == 0 && sgn(y - b.y) == 0 && sgn(z - b.z) == 0;
    }
    double len2() const {
        return x * x + y * y + z * z;
    }
    double len() const {
        return sqrt(len2());
    }
    point tolen(const double &l) {
        double len = l / sqrt(len2());return point(x * len, y * len, z * len);
    }
    int read() {
        return scanf("%lf%lf%lf", &x, &y, &z);
    }
    void print() const {
        printf("(%lf %lf %lf)\n", x, y, z);
    }
};
double dot(const point &a, const point &b){
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
double dot(const point &a, const point &b, const point &c) {
    return (b.x - a.x) * (c.x - a.x) + (b.y - a.y) * (c.y - a.y) + (b.z - a.z) * (c.z - a.z);
}
point cross(const point &a, const point &b) {
    return point(a.y * b.z - a.z * b.y,-(a.x * b.z - a.z * b.x),a.x * b.y - a.y * b.x);
}
point cross(const point &a, const point &b, const point &c) {
    return point((b.y - a.y) * (c.z - a.z) - (b.z - a.z) * (c.y - a.y),-((b.x - a.x) * (c.z - a.z) - (b.z - a.z) * (c.x - a.x)),(b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x));
}
point s[N];
struct this_face
{
    int a,b,c;
    this_face(){}
    this_face (int _a ,int _b , int _c ): a (_a ), b (_b) , c (_c) {}
    double area (){
        point q = cross( s[a] , s[b] , s[c] );
        return q.len();
    }
    bool same_side(const point &q , const point & p){
        return sgn ( dot(s[a] - q, cross(s[b] - q, s[c] - q)) * dot(s[a] - p , cross( s[b] - p , s[c] - p)) ) > 0 ;
    }
};
int map[N][N];
struct line{
    int a,b;line(){}line(int _a,int _b ) : a(_a),b(_b){}
};
vector <this_face> convex , face_tmp ;vector <int> int_tmp;vector <line> line_tmp;
int main(){
    int i , j , k , n , m ;
    while( scanf("%d",&n)!=EOF ){
        for ( i = 0 ; i < n; i ++ )
            s[i].read();
        convex.clear ();
        memset( map , 0 , sizeof( map ) );
        if ( n <=2 ){
            printf("0.000\n");
            continue;
        }
        if ( n == 3 ){
            point p = cross( s[0],s[1],s[2] );
            printf("%.3lf\n",(p.len())*.5 );
            continue;
        }
        for ( i = 0 ; i < 4 ;i ++ )
            convex.push_back( this_face ( i , (i+1)%4 , (i+2)%4 ) ) ;
        point center = ( s[0] + s[1] + s[2] + s[3] ) / 4;
        for ( i = 4 ; i < n ; i ++ ) {
            face_tmp.clear();line_tmp.clear();
            for ( j = 0 ; j < convex.size() ; j ++ )
                if ( ! (convex[j].same_side( center , s[i] )) )
                {
                    if( map[convex[j].a][convex[j].b] == 0 )map[convex[j].a][convex[j].b] = map[convex[j].b][convex[j].a] = 1;
                    else map[convex[j].a][convex[j].b] = map[convex[j].b][convex[j].a] = 0;
                    line_tmp.push_back( line( convex[j].a , convex[j].b ) ) ;
                    if( map[convex[j].c][convex[j].b] == 0 )map[convex[j].c][convex[j].b] = map[convex[j].b][convex[j].c] = 1;
                    else map[convex[j].c][convex[j].b] = map[convex[j].b][convex[j].c] = 0;
                    line_tmp.push_back( line( convex[j].c , convex[j].b ) ) ;
                    if( map[convex[j].c][convex[j].a] == 0 ) map[convex[j].c][convex[j].a] = map[convex[j].a][convex[j].c] = 1;
                    else map[convex[j].c][convex[j].a] = map[convex[j].a][convex[j].c] = 0;
                    line_tmp.push_back( line( convex[j].c , convex[j].a ) ) ;
                }
                else face_tmp.push_back( convex[j] );
            convex.clear();
            for ( j = 0 ;j < face_tmp.size() ; j ++ )convex.push_back( face_tmp[j] );
            for ( j = 0 ;j < line_tmp.size() ; j ++ )
                if ( map [ line_tmp[j].a ][ line_tmp[j].b ] == 1 ){
                    convex.push_back( this_face ( line_tmp[j].a , line_tmp[j].b , i ) );
                    map[ line_tmp[j].a ][ line_tmp[j].b ] = map[ line_tmp[j].b ][ line_tmp[j].a ] = 0;
                }
        }
        double area = 0 ;
        for ( i = 0 ; i < convex.size() ; i ++ )
            area += convex[i].area();
        printf("%.3lf\n",area *0.5);
    }
    return 0;
}
