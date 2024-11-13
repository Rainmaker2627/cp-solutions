#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod=1e9+7;

struct matrix {
	int r, c;
	vector<vector<int>> v;

	matrix(vector<vector<int>> e) {
		r=e.size();
		c=e[0].size();
		v.assign(r, vector<int>(c, 0));
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				v[i][j]=e[i][j];
			}
		}
	}

	void operator*=(matrix m) {
		assert(c==m.r);
		vector<vector<int>> p(r, vector<int>(m.c, 0));
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < m.c; ++j) {
				for (int k = 0; k < c; ++k) {
					p[i][j]=(p[i][j]+v[i][k]*m.v[k][j]%mod)%mod;
				}
			}
		} c=m.c; v=p;
	}
};

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	matrix id({{1,0,0,0,0,0},{0,1,0,0,0,0},{0,0,1,0,0,0},{0,0,0,1,0,0},{0,0,0,0,1,0},{0,0,0,0,0,1}});
	matrix m({{1,1,1,1,1,1},{1,0,0,0,0,0},{0,1,0,0,0,0},{0,0,1,0,0,0},{0,0,0,1,0,0},{0,0,0,0,1,0}});
	while (n) {
		if (n%2) id*=m;
		m*=m; n/=2;
	} cout << id.v[0][0]%mod << '\n';

	return 0;
}