#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define sz(a) int((a).size())
#define all(X) (X).begin(), (X).end()
typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;

class LotteryCheating {
public:
	int minimalChange(string ID);
};

vector<string> v;

inline int go(string &s1, string &s2)
{
	int ret = 0;
	for (int i = 0; i < sz(s1); ++i) {
		if (s1[i] != s2[i]) ++ret;
	}
	return ret;
}

int LotteryCheating::minimalChange(string ID) {
	v.clear();
	int len = ID.size();
	for (long long i = 0; ; ++i) {
		long long j = i * i;
		stringstream S;
		S << j;
		string s = S.str();
		if (s.size() > len) break;
		while (s.size() < len) s = '0' + s;
		v.push_back(s);
	}
	int ret = len;
	for (int i = 0; i < v.size(); ++i) {
		ret = min(ret, go(v[i], ID));
	}
	return ret;
}
