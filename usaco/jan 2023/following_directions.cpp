#include<bits/stdc++.h>
using namespace std;
#define int long long

struct field {
	vector<vector<int>> d, g;
	vector<int> r, c;
	int n;

	field(int a) {
		n=a;
		g.assign(n+1, vector<int>(n+1, 0));
		d.assign(n, vector<int>());
		r.reserve(n); c.reserve(n);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				char c;
				cin >> c;
				g[i][j]=1;
				d[i].push_back(c=='D');
			} cin >> r[i];
		} for (int i = 0; i < n; ++i) cin >> c[i];

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (d[i][j]) g[i+1][j]+=g[i][j];
				else g[i][j+1]+=g[i][j];
			}
		}
	}

	void print() {
		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= n; ++j) {
				cout << g[i][j] << ' ';
			} cout << '\n';
		}
	}

	void update(int i, int j) {
		int a=--i, b=--j;
		while (a<n && b<n) {
			if (d[a][b]) a++;
			else b++;
			g[a][b]-=g[i][j];
		} d[i][j]^=1;
		a=i; b=j;
		while (a<n && b<n) {
			if (d[a][b]) a++;
			else b++;
			g[a][b]+=g[i][j];
		}
	}

	int query() {
		int ans=0;
		for (int i = 0; i < n; ++i) {
			ans+=r[i]*g[i][n]+c[i]*g[n][i];
		} return ans;
	}
};

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, q;
	cin >> n;
	field f(n);

	cin >> q;
	cout << f.query() << '\n';
	for (int i = 0; i < q; ++i) {
		int a, b;
		cin >> a >> b;
		f.update(a, b);
		cout << f.query() << '\n';
	}
	
	return 0;
}