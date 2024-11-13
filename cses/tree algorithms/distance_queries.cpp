#include<bits/stdc++.h>
using namespace std;

struct sparse {
	int n;
	vector<int> in, h;
	vector<vector<int>> sp;

	sparse(vector<int>& in, vector<int>& h, vector<int>& r) {
		int m=1; this->n=r.size();
		while ((1<<m)<n) m++;
		sp.assign(m, vector<int>(n, 0));
		for (int i = 0; i < n; ++i)	sp[0][i]=h[r[i]];
		for (int i = 1; i < m; ++i) {
			for (int j = 0; j < n-(1<<(i-1)); ++j) {
				sp[i][j]=min(sp[i-1][j], sp[i-1][j+(1<<(i-1))]);
			}
		} this->in=in;
	}

	int query(int a, int b) {
		if (a==b) return sp[0][in[a]];
		if (in[a]>in[b]) swap(a, b);
		int d=in[b]-in[a]+1, p=1;
		while ((1<<p)<d) { p++; } p--;
		return min(sp[p][in[a]], sp[p][in[b]-(1<<p)]);
	}
};

int t=0;
vector<int> h, in, ord;

void dfs(int u, int p, vector<vector<int>>& g) {
	in[u]=t++; h[u]=h[p]+1;
	ord.push_back(u);
	for (auto v : g[u]) {
		if (v==p) continue;
		dfs(v, u, g);
		ord.push_back(u); t++;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, q;
	cin >> n >> q;
	in.assign(n+1, 0);
	h.assign(n+1, 0);
	vector<vector<int>> g(n+1, vector<int>());
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	} dfs(1, 1, g);
	sparse sp(in, h, ord);

	for (int i = 0; i < q; ++i) {
		int a, b;
		cin >> a >> b;
		cout << h[a]+h[b]-2*sp.query(a, b) << '\n';
	}

	return 0;
}