#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

int const N= 100010;
int n, m;

struct Node{
    int Lx1, Rx1, Ax1;
    int Lx0, Rx0, Ax0;
    int op1, op2, op3;
    int num;
};
Node tb[N<<2];
int dat[N];

void inline toRoot( int rt, int L, int R ){
    int mid= (L+ R)>>1;
    tb[rt].num= tb[rt<<1].num+ tb[rt<<1|1].num;
    tb[rt].Ax1= max( tb[rt<<1].Ax1, tb[rt<<1|1].Ax1 );
    if( tb[rt<<1].Lx1== mid- L+ 1 ) tb[rt].Lx1= tb[rt<<1].Lx1+ tb[rt<<1|1].Lx1;
    else tb[rt].Lx1= tb[rt<<1].Lx1;
    if( tb[rt<<1|1].Rx1== R- mid ) tb[rt].Rx1= tb[rt<<1|1].Rx1+ tb[rt<<1].Rx1;
    else tb[rt].Rx1= tb[rt<<1|1].Rx1;
    tb[rt].Ax1= max( tb[rt<<1].Rx1+ tb[rt<<1|1].Lx1, tb[rt].Ax1 );
    tb[rt].Ax0= max( tb[rt<<1].Ax0, tb[rt<<1|1].Ax0 );
    if( tb[rt<<1].Lx0== mid- L+ 1 ) tb[rt].Lx0= tb[rt<<1].Lx0+ tb[rt<<1|1].Lx0;
    else tb[rt].Lx0= tb[rt<<1].Lx0;
    if( tb[rt<<1|1].Rx0== R- mid ) tb[rt].Rx0= tb[rt<<1|1].Rx0+ tb[rt<<1].Rx0;
    else tb[rt].Rx0= tb[rt<<1|1].Rx0;
    tb[rt].Ax0= max( tb[rt<<1].Rx0+ tb[rt<<1|1].Lx0, tb[rt].Ax0 );
}

void inline Down( int rt, int L, int R ){
    int mid= (L+ R)>>1;
    if( tb[rt].op3 ){
		tb[rt<<1].op3= 1- tb[rt<<1].op3;
		tb[rt<<1|1].op3= 1- tb[rt<<1|1].op3;

        int x= tb[rt<<1].Lx0, y= tb[rt<<1].Rx0, z= tb[rt<<1].Ax0;

        tb[rt<<1].Lx0= tb[rt<<1].Lx1;
        tb[rt<<1].Rx0= tb[rt<<1].Rx1;
        tb[rt<<1].Ax0= tb[rt<<1].Ax1;

        tb[rt<<1].Lx1= x; tb[rt<<1].Rx1= y; tb[rt<<1].Ax1= z;
        tb[rt<<1].num= mid- L+ 1- tb[rt<<1].num;

        x= tb[rt<<1|1].Lx0, y= tb[rt<<1|1].Rx0, z= tb[rt<<1|1].Ax0;

        tb[rt<<1|1].Lx0= tb[rt<<1|1].Lx1;
        tb[rt<<1|1].Rx0= tb[rt<<1|1].Rx1;
        tb[rt<<1|1].Ax0= tb[rt<<1|1].Ax1;

        tb[rt<<1|1].Lx1= x; tb[rt<<1|1].Rx1= y; tb[rt<<1|1].Ax1= z;
        tb[rt<<1|1].num= R- mid- tb[rt<<1|1].num;
    }

    tb[rt].op1= tb[rt].op2= tb[rt].op3= 0;
}

void build( int L, int R, int rt ){
	tb[rt].op1= tb[rt].op2= tb[rt].op3= 0;

    if( L== R ){
        if( dat[L]== 1 ) {
            tb[rt].Lx1= tb[rt].Rx1= tb[rt].Ax1= 1;
            tb[rt].Lx0= tb[rt].Rx0= tb[rt].Ax0= 0;
            tb[rt].num= 1;
        }
        else {
            tb[rt].Lx1= tb[rt].Rx1= tb[rt].Ax1= 0;
            tb[rt].Lx0= tb[rt].Rx0= tb[rt].Ax0= 1;
            tb[rt].num= 0;
        }
        return;
    }
    int mid= (L+ R)>>1;
    build( L, mid, rt<<1 );
    build( mid+ 1, R, rt<<1|1 );
    toRoot( rt, L, R );
}

void update( int x, int y, int d, int L, int R, int rt ){
    if( L!= R ) Down( rt, L, R );
    if( L== x && R== y ){
        if( d== 3 ){
			tb[rt].op3= 1;
            int a= tb[rt].Lx0, b= tb[rt].Rx0, c= tb[rt].Ax0;

            tb[rt].Lx0= tb[rt].Lx1;
            tb[rt].Rx0= tb[rt].Rx1;
            tb[rt].Ax0= tb[rt].Ax1;

            tb[rt].Lx1= a; tb[rt].Rx1= b; tb[rt].Ax1= c;

            tb[rt].num= R- L+ 1- tb[rt].num;
        }

        return;
    }
    int mid= (L+ R)>>1;
    if( y<= mid ) update( x, y, d, L, mid, rt<<1 );
    else if( x> mid ) update( x, y, d, mid+ 1, R, rt<<1|1 );
    else{
        update( x, mid, d, L, mid, rt<<1 );
        update( mid+ 1, y, d, mid+ 1, R, rt<<1|1  );
    }
    toRoot( rt, L, R );
}

int query( int x, int y, int d, int L, int R, int rt ){
    if( L!= R ) Down( rt, L, R );

    if( x== L && y== R ){
        return tb[rt].Ax1;
    }

    int mid= (L+ R)>>1;
    if( y<= mid ) return query( x, y, d, L, mid, rt<<1 );
    else if( x> mid ) return query( x, y, d, mid+ 1, R, rt<<1|1 );
    else{
        int a= 0, b= 0;


        a= query( x, mid, d, L, mid, rt<<1 );
        b= query( mid+ 1, y, d, mid+ 1, R, rt<<1|1 );

        int c= min( mid- x+ 1, tb[rt<<1].Rx1 )+ min( y- mid, tb[rt<<1|1].Lx1 );

        return max( a, max( b, c ) );
    }
}

int main(){
    int test;

    while( ~scanf("%d",&n) ){

        for( int i= 1; i<= n; ++i ) scanf("%d", dat+ i );
        build( 1, n, 1 );
        scanf("%d", &m);
        for( int i= 0; i< m; ++i ){
            int op, a, b;
            scanf("%d%d%d", &op, &a, &b );

            if( op == 1 )
                update( a, b, 3, 1, n, 1 );
            else
                printf("%d\n", query( a, b, 5, 1, n, 1 ) );
        }
    }

    return 0;
}
