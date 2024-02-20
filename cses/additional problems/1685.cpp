#include<bits/stdc++.h>
using namespace std;

vector<bool> s;

void dfs_scc(int u, vector<int>& c, vector<vector<int>>& g) {
	s[u]=true;
	for (auto v : g[u]) {
		if (s[v]) continue;
		dfs_scc(v, c, g);
	} c.push_back(u);
}

void dfs(int u, vector<vector<int>>& g) {

}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> f(n+1, vector<int>()), r(n+1, vector<int>());
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		f[a].push_back(b);
		r[b].push_back(a);
	}

	int c=0;
	s.assign(n+1, false);
	vector<int> tout, comp(n+1);
	for (int i = 1; i <= n; ++i) {
		if (!s[i]) dfs_scc(i, tout, f);
	} reverse(tout.begin(), tout.end());
	s.assign(n+1, false);
	for (auto u : tout) {
		if (s[u]) continue;
		vector<int> t;
		dfs_scc(u, t, r); c++;
		for (auto v : t) {
			comp[v]=c;
		}
	}

	vector<int> ind(c+1, 0), outd(c+1, 0);
	vector<vector<int>> scc(c+1, vector<int>());
	for (int i = 1; i <= n; ++i) {
		for (auto v : f[i]) {
			if (comp[i]==comp[v]) continue;
			scc[comp[i]].push_back(comp[v]);
			ind[comp[v]]++; outd[comp[i]]++;
		}
	} 

	// consider the sources (set A) and sinks (set B)
	// let U={u1, u2, ..., ui}=AnB
	// join u1->u2, u2->u3, ..., not ui->u1. For some v not in U, join v->u1, ui->v.
	// find a "blocking" matching (similar to Dicnic's algorithm)
		// ie a matching that cannot be extended by adding a disjoint path from a source to a sink
	// let it be A1->B1, A2->B2, ..., Ak->Bk
	// join B1->A2, B2->A3, ..., Bk->A1
	// this forms a scc X. We now for some set of a in A, a->X, and for some set of b in B, X->b
	// greedily add the reverse of these edges
	// we are done in O(n) time

	return 0;
}