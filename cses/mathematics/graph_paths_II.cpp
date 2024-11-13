#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;

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
					if (v[i][k]==0 || m.v[k][j]==0) continue;
					if (p.v[i][j]==0) p.v[i][j]=v[i][k]+m.v[k][j];
					p.v[i][j]=min(p.v[i][j], v[i][k]+m.v[k][j]);
				}
			}
		} return p;
	}
};

matrix exp(matrix a, int b) {
	matrix x(0, 0);
	while (b) {
		if (b%2) {
			if (x.r==0) x=a;
			else x=x*a;
		}
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
		int a, b, c;
		cin >> a >> b >> c;
		if (t.v[a-1][b-1]==0) t.v[a-1][b-1]=c;
		else t.v[a-1][b-1]=min(t.v[a-1][b-1], c);
	}

	matrix r=exp(t, k);
	cout << (r.v[0][n-1]==0?-1:r.v[0][n-1]) << '\n';

	return 0;
}