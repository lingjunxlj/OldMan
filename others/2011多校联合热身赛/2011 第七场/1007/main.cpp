#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<sstream>
#include<cassert>
#include<queue>
#include<stack>

#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)
#define ALL(C)     (C).begin(),(C).end()
#define pb         push_back
#define mp         make_pair
#define vint       vector<int>
#define FOR(it,o)  for(__typeof((o).begin()) it=(o).begin(); it!=(o).end(); ++it)
#define lli	    long long int
#define ld	    long double

using namespace std;


main(){

    int dataset;

    cin >> dataset;

    rep(data, dataset)
    {
        lli inn;
        cin >> inn;
        string str;
        cin >> str;
        int ans = 0;

        rep(zero, str.length())
        {
            int pos = 0, round = 0;
            string s = str;
            while(1)
            {
                int base = 1;
                if(round == zero)
                    base = 0;
                round++;
                int n = inn;
                int npos = pos;
                npos += n;

                npos -= base;
                npos %= s.length();
                s.erase(s.begin() + npos);

                pos = npos;
                pos %= s.length();
                if(s.length() == 0 || find(s.begin(), s.end(), 'G') == s.end() || s.find('B') == string::npos)
                {
                    break;
                }
            }
            ans = max(ans, count(s.begin(), s.end(), 'B'));
        }
        cout << ans << endl;
    }
}
