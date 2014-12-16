#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 10001;

bool _use[N];
int _g[2][N][N];              // use adjcent matrix
int _deg[2][N];                            // degree
int _tmp[2][N];                            // the sorted degree sequence
int _map[N];                            // mapping
int _n, _m,  _n1, _m1;

bool Judge(int d) {
    for (int i = 0; i < d; ++i) {
        if (_g[1][d][i] != _g[0][_map[d]][_map[i]]) return false;
    }
    // return 0;
    return true;
}

bool DFS(int d) {
    if (d == _n) return true;
    for (int i = 0; i < _n; ++i) {

                            // only map the nodes have same degree
        if (_deg[0][i] != _deg[1][d] || _use[i]) continue;

        _map[d] = i;
        _use[i] = true;
        if (Judge(d) && DFS(d + 1)) return true;
        _use[i] = false;
    }
    return false;
}

int main() {
    int tc;
    int tt = 1;
    scanf("%d", &tc);
    while (tc--) {
        memset(_use, 0, sizeof(_use));
        memset(_deg, 0, sizeof(_deg));
        memset(_g, 0, sizeof(_g));
        scanf("%d%d", &_n, &_m);
        int i, u, v;
        for (i = 0; i < _m; ++i) {
            scanf("%d%d", &u, &v);
            --u; --v;
            ++_g[0][u][v];
            ++_g[0][v][u];
            ++_deg[0][u];
            ++_deg[0][v];
        }
        scanf("%d%d", &_n1, &_m1);
        for (i = 0; i < _m1; ++i) {
            scanf("%d%d", &u, &v);
            --u; --v;
            ++_g[1][u][v];
            ++_g[1][v][u];
            ++_deg[1][u];
            ++_deg[1][v];
        }
        if (_n != _n1 || _m != _m1)
        {
            printf("Case #%d: NO\n", tt++);
            continue;
        }
        memcpy(_tmp, _deg, sizeof(_tmp));
        sort(_tmp[0], _tmp[0] + _n);
        sort(_tmp[1], _tmp[1] + _n);

        // judge the degree sequence
        for (i = 0; i < _n; ++i) {
            // if (_deg[0][i] != _deg[1][i]) break;
            if (_tmp[0][i] != _tmp[1][i]) break;
        }
        if (i < _n) {
            printf("Case #%d: NO\n", tt++);
            continue;
        }

        if (DFS(0)) printf("Case #%d: YES\n", tt++);
        else printf("Case #%d: NO\n", tt++);
    }
    return 0;
}
