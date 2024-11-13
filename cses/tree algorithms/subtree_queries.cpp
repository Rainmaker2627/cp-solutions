#include<bits/stdc++.h>
using namespace std;
#define int long long

struct segtree {
	int n;
	vector<int> st;

	segtree(vector<int>& a) {
		n=a.size();
		while (n&(n-1)) n++;
		st.assign(2*n, 0);
		for (int i = n; i < n+a.size(); ++i) st[i]=a[i-n];
		for (int i = n-1; i > 0; --i) st[i]=st[2*i]+st[2*i+1];
	}

	void update(int p, int v, int n=1, int nl=1, int nr=1) {
		if (n==1) nr=this->n;
		if (nr<p || p<nl) return;
		if (nl==nr) { st[n]=v; return; }
		update(p, v, 2*n, nl, (nl+nr)/2);
		update(p, v, 2*n+1, (nl+nr)/2+1, nr);
		st[n]=st[2*n]+st[2*n+1];
	}

	int query(int ql, int qr, int n=1, int nl=1, int nr=1) {
		if (n==1) nr=this->n;
		if (nr<ql || qr<nl) return 0;
		if (ql<=nl && nr<=qr) return st[n];
		return query(ql, qr, 2*n, nl, (nl+nr)/2)+query(ql, qr, 2*n+1, (nl+nr)/2+1, nr);
	}
};

int t=1;
vector<int> v, eul, tin, tout;
vector<vector<int>> adj;

void dfs(int u, int p) {
	tin[u]=t++;
	eul.push_back(v[u]);
	for (auto v : adj[u]) {
		if (v==p) continue;
		dfs(v, u);
	} tout[u]=t;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, q;
	cin >> n >> q;
	
	v.assign(n+1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
	}

	adj.assign(n+1, vector<int>());
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	tin.assign(n+1, 0);
	tout.assign(n+1, 0);
	dfs(1, 1);
	segtree st(eul);
	for (int i = 0; i < q; ++i) {
		int t;
		cin >> t;
		if (t==1) {
			int s, x;
			cin >> s >> x;
			st.update(tin[s], x);
		} else {
			int s;
			cin >> s;
			cout << st.query(tin[s], tout[s]-1) << '\n';
		}
	}

	return 0;
}