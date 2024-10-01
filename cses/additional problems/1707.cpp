#include<bits/stdc++.h>
using namespace std;

struct lazy {
	int n;
	vector<int> st, lz;

	lazy(int a) {
		n=a;
		while (n&(n-1)) n++;
		vector<int> b(2*n, 0), c(2*n, 0);
		for (int i = n; i < n+a; ++i) cin >> b[i];
		for (int i = n-1; i > 0; --i) b[i]=b[2*i]+b[2*i+1];
		swap(b, st); swap(lz, c);
	}

	void push(int n) {
		st[n]+=lz[n];
		if (n<this->n) {
			lz[2*n]+=lz[n]/2;
			lz[2*n+1]+=lz[n]/2;
		} lz[n]=0;
	}

	void update(int a, int b, int v, int n=1, int l=1, int r=-1) {
		if (n==1) r=this->n;
		if (r<a || l>b) return;
		if (a<=l && r<=b) { lz[n]+=(r-l+1)*v; return; }
		st[n]+=(min(b, r)-max(a, l)+1)*v;
		update(a, b, v, 2*n, l, (l+r)/2);
		update(a, b, v, 2*n+1, (l+r)/2+1, r);
	}

	int query(int a, int b, int n=1, int l=1, int r=-1) {
		if (n==1) r=this->n;
		push(n);
		if (r<a || l>b) return 0;
		if (a<=l && r<=b) return st[n]+lz[n];
		return query(a, b, 2*n, l, (l+r)/2) + query(a, b, 2*n+1, (l+r)/2+1, r);
	}
};

int t;
vector<int> p, a, in, out;
vector<vector<int>> g;

void dfs(int u, set<int> s) {
	in[u]=++t;
	for (auto v : g[u]) {
		dfs(v, s);
	}
	out[u]=t;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		p.assign(n+1, 0);
		a.assign(n+1, 0);
		g.assign(n+1, vector<int>());
		for (int i = 2; i <= n; ++i) {
			cin >> p[i];
			c[p[i]].push_back(i);
		}

		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}

		t=0;
		in.assign(n+1, 0);
		out.assign(n+1, 0);
		dfs1(1, 1);

	}

	return 0;
}