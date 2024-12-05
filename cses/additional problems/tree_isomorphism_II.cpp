#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;

struct tree {
	int n, r;
	crope comp;
	vector<int> s;
	vector<vector<int>> adj;

	tree(int n) {
		this->n=n;
		s.assign(n+1, 0);
		adj.assign(n+1, vector<int>());
		for (int i = 0; i < n-1; ++i) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		} dfs_sz(r=1, 1);
		center(r);
		comp=dfs_rep(r, r);
	}

	void dfs_sz(int u, int p) {
		s[u]=1;
		for (auto v : adj[u]) {
			if (v==p) continue;
			dfs_sz(v, u);
			s[u]+=s[v];
		}
	}

	crope dfs_rep(int u, int p) {
		crope s="(";
		vector<crope> t;
		for (auto v : adj[u]) {
			if (v==p) continue;
			t.push_back(dfs_rep(v, u));
		} sort(t.begin(), t.end());
		for (auto i : t) s+=i;
		return s+=")";
	}

	void center(int u) {
		for (auto v : adj[u]) {
			if (2*s[v]<s[u]) continue;
			if (2*s[v]>s[u]) {
				s[u]-=s[v];
				s[v]=n;
				center(r=v);
			} else {
				s[u]-=s[v];
				adj.push_back({u, v});
				s.push_back(r=n+1);
			}
			break;
		}
	}

	bool operator==(tree b) {
		return comp==b.comp;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		tree a(n), b(n);
		cout << (a==b?"YES\n":"NO\n");
	}

	return 0;
}