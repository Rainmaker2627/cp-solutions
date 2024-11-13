#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;
const int mod=1e9+7;

struct matrix {
	int r, c;
	vector<vector<int>> v;

	matrix(int r, int c) {
		this->r=r, this->c=c;
		v.assign(r, vector<int>(c, 0));
	}

	matrix operator*(matrix m) {
		assert(c==m.r);
		matrix p(r, m.c);
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < m.c; ++j) {
				for (int k = 0; k < c; ++k) {
					p.v[i][j]=(p.v[i][j]+v[i][k]*m.v[k][j])%mod;
				}
			}
		} return p;
	}
};

matrix exp(matrix a, int b) {
	matrix x(n, n);
	for (int i = 0; i < n; ++i) x.v[i][i]=1;
	while (b) {
		if (b%2) x=x*a;
		a=a*a;
		b/=2;
	} return x;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int m, k;
	cin >> n >> m >> k;
	matrix t(n, n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		t.v[a-1][b-1]++;
	}

	cout << exp(t, k).v[0][n-1] << '\n';

	return 0;
}