#include<bits/stdc++.h>
using namespace std;
#define int long long

<<<<<<< Updated upstream
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
	
=======
int n, q;
vector<int> r, c;
vector<vector<int>> d, a;

void update(int i, int j) {
	int x=i, y=j;
	while (x<n+1 && y<n+1) {
		if (d[x][y]) x++;
		else y++;
		a[x][y]-=a[i][j];
	} x=i; y=j;
	d[i][j]^=1;
	while (x<n+1 && y<n+1) {
		if (d[x][y]) x++;
		else y++;
		a[x][y]+=a[i][j];
	}
}

int ans() {
	int ans=0;
	for (int i = 0; i < n; ++i) {
		ans+=a[i][n]*r[i] + a[n][i]+c[i];
	} return ans;
}

signed main () {
	// cin.tie(0)->sync_with_stdio(false);

	cin >> n;
	r.reserve(n); c.reserve(n);
	d.assign(n, vector<int>(n));
	a.assign(n+1, vector<int>(n+1, 1));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			char t;
			cin >> t;
			d[i][j]=(t=='D');
		} cin >> r[i];
	} for (int i = 0; i < n; ++i) {
		cin >> c[i];
		a[i][n]=a[n][i]=0;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (d[i][j]) a[i+1][j]+=a[i][j];
			else a[i][j+1]+=a[i][j];
		}
	}

	cin >> q;
	for (int i = 0; i < q; ++i) {
		int a, b;
		cin >> a >> b;
		update(a, b);
		cout << ans() << '\n';
	}

	cin >> n;
>>>>>>> Stashed changes
	return 0;
}