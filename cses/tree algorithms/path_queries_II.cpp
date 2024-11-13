#include<bits/stdc++.h>
using namespace std;

struct segtree {
	int n;
	vector<int> st;

	void set(vector<int>& v) {
		n=v.size();
		st.assign(2*n, 0);
		for (int i = n; i < n+v.size(); ++i) st[i]=v[i-n];
		for (int i = n-1; i > 0; --i) st[i]=max(st[2*i], st[2*i+1]);
	}

	int query(int a, int b) {
		int s=0;
		a+=n-1; b+=n-1;
		while (a<=b) {
			if (a%2==1) s=max(s, st[a++]);
			if (b%2==0) s=max(s, st[b--]);
			a/=2; b/=2;
		} return s;
	}

	void update(int s, int x) {
		for (st[s+=n-1]=x; s>1; s/=2) st[s/2]=max(st[s], st[s^1]);
	}
};

struct hld {
	int n, t=0;
	vector<vector<int>> e;
	vector<int> a, x, pos, root, par, depth;
	segtree st;

	int dfs_sz(int u=1, int p=1) {
		int sz=1, m=0;
		for (auto& v : e[u]) {
			if (v==p) continue;
			int t=dfs_sz(v, u);
			if (t>m) {
				swap(v, e[u][0]); m=t;
			} sz+=t;
		} return sz;
	}

	void dfs_hld(int u=1, int p=1) {
		pos[u]=++t; par[u]=p;
		depth[u]=depth[p]+1;
		a.push_back(x[u]);
		for (auto v : e[u]) {
			if (v==p) continue;
			root[v]=(v==e[u][0]?root[u]:v);
			dfs_hld(v, u);
		}
	}

	hld(int n, vector<int>& x, vector<vector<int>>& e) {
		this->n=n; this->e=e; this->x=x;
		pos.assign(n+1, 0); par.assign(n+1, 0);
		root.assign(n+1, 0); depth.assign(n+1, 0);
		dfs_sz(); dfs_hld();
		st.set(a);
	}

	int query(int a, int b) {
		int s=0;
		while (root[a]!=root[b]) {
			if (depth[root[a]]>depth[root[b]]) swap(a, b);
			s=max(s, st.query(pos[root[b]], pos[b]));
			b=par[root[b]];
		} if (depth[a]>depth[b]) swap(a, b);
		return max(s, st.query(pos[a], pos[b]));
	}

	void update(int s, int x) {
		st.update(pos[s], x);
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, q;
	cin >> n >> q;
	vector<int> v(n+1);
	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
	}

	vector<vector<int>> e(n+1, vector<int>());
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}

	hld tree(n, v, e);
	for (int i = 0; i < q; ++i) {
		int t, s, x;
		cin >> t >> s >> x;
		if (t==1) tree.update(s, x);
		else cout << tree.query(s, x) << " \n"[i==q-1];
	}

	return 0;
}