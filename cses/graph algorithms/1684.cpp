#include<bits/stdc++.h>
using namespace std;

vector<bool> s;

void dfs(int u, vector<int>& c, vector<vector<int>>& g) {
	s[u]=true;
	for (auto v : g[u]) {
		if (s[v]) continue;
		dfs(v, c, g);
	} c.push_back(u);
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> f(2*m+1, vector<int>()), r(2*m+1, vector<int>());
	for (int i = 0; i < n; ++i) {
		char x, y; int a, b;
		cin >> x >> a >> y >> b;
		a=(x=='-'?-a:a); b=(y=='-'?-b:b);
		f[-a+m].push_back(b+m); r[b+m].push_back(-a+m);
		f[-b+m].push_back(a+m); r[a+m].push_back(-b+m);
	}

	int c=0;
	s.assign(2*m+1, false);
	vector<int> tout, comp(2*m+1, 0);
	for (int i = 0; i <= 2*m; ++i) {
		if (i==m || s[i]) continue;
		dfs(i, tout, f);
	} reverse(tout.begin(), tout.end());
	s.assign(2*m+1, false);
	for (auto i : tout) {
		if (s[i]) continue;
		vector<int> t;
		dfs(i, t, r); c++;
		for (auto i : t) {
			comp[i]=c;
			i=abs(m-i);
		}
	}

	bool b=false;
	vector<int> in(c+1, 0);
	vector<vector<int>> elem(c+1, vector<int>()), scc(c+1, vector<int>());
	for (int i = 0, j = 2*m; i < m && !b; ++i, j--) {
		b=(comp[i]==comp[j]);
		for (auto v : f[i]) {
			if (comp[i]==comp[v]) continue;
			scc[comp[i]].push_back(comp[v]);
			in[comp[v]]++;
		} elem[comp[i]].push_back(i);
		for (auto v : f[j]) {
			if (comp[j]==comp[v]) continue;
			scc[comp[j]].push_back(comp[v]);
			in[comp[v]]++;
		} elem[comp[j]].push_back(j);
	}

	if (!b) {
		queue<int> q;
		vector<bool> ans(m+1, true);
		for (int i = 0; i < c; ++i) {
			if (in[i]==0) q.push(i);
		}

		while (!q.empty()) {
			int u=q.front();
			for (auto v : elem[u]) {
				int t=abs(m-v);
				ans[t]=(v>m);
			} q.pop();
			for (auto v : scc[u]) {
				if (in[v]--==1) q.push(v);
			}
		}

		for (int i = 1; i <= m; ++i) {
			cout << (ans[i]?"+ ":"- ");
		} cout << '\n';
	} else cout << "IMPOSSIBLE\n";
	
	return 0;
}