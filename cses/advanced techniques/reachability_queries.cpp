#pragma GCC target("popcnt")
#include<bits/stdc++.h>
using namespace std;
 
vector<bool> s;
 
void dfs(int u, vector<int>& t, vector<vector<int>>& e) {
	s[u]=true;
	for (auto v : e[u]) {
		if (!s[v]) dfs(v, t, e);
	} t.push_back(u);
}
 
int main() {
	cin.tie(0)->sync_with_stdio(false);
 
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<int>> fwd(n+1, vector<int>()), rev(n+1, vector<int>());
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		fwd[a].push_back(b);
		rev[b].push_back(a);
	}
 
	vector<int> t;
	s.assign(n+1, false);
	for (int i = 1; i <= n; ++i) {
		if (!s[i]) dfs(i, t, fwd);
	} reverse(t.begin(), t.end());
 
	int scc=0;
	vector<int> comp(n+1, 0);
	s.assign(n+1, false);
	for (auto i : t) {
		if (s[i]) continue;
		scc++;
		vector<int> cc;
		dfs(i, cc, rev);
		for (auto j : cc) {
			comp[j]=scc;
		}
	}
 
	vector<int> in(++scc, 0);
	vector<vector<int>> cg(scc, vector<int>());
	for (int i = 1; i <= n; ++i) {
		for (auto j : fwd[i]) {
			if (comp[i]==comp[j]) continue;
			cg[comp[j]].push_back(comp[i]);
			in[comp[i]]++;
		}
	}
 
	queue<int> ts;
	vector<bitset<50001>> bs(scc, bitset<50001>());
	for (int i = 1; i < scc; ++i) {
		if (in[i]==0) ts.push(i);
		bs[i].set(i);
	}
 
	while (!ts.empty()) {
		int u=ts.front();
		ts.pop();
		for (auto v : cg[u]) {
			if (--in[v]==0) ts.push(v);
			bs[v]|=bs[u];
		}
	}
 
	for (int i = 0; i < q; ++i) {
		int a, b;
		cin >> a >> b;
		cout << (bs[comp[a]][comp[b]]?"YES":"NO") << '\n';
	}
 
	return 0;
}