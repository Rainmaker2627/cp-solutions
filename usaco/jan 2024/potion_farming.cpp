#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> e, t;
vector<int> l;
int m;

void dfs1(int u, int p) {
	for (auto v : e[u]) {
		if (v==p) continue;
		dfs1(v, u);
	} if (e[u].size()==1 && u!=p) m++;
}

void dfs2(int u, int p, stack<int>& s) {
	for (auto i : t[u]) if (i<=m) s.push(i);
	for (auto v : e[u]) {
		if (v==p) continue;
		dfs2(v, u, s);
	} if (e[u].size()==1 && s.size()) { l[s.top()]=u; s.pop(); }
	for (auto i : t[u]) if (i<=m && !l[i]) s.pop();
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int n;
	cin >> n;
	t.assign(n+1, vector<int>());
	e.assign(n+1, vector<int>());
	l.assign(n+1, 0);
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		t[x].push_back(i);
	}
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}

	int a=0;
	stack<int> s;
	dfs1(1, 1); dfs2(1, 1, s);
	for (int i = 1; i <= n; ++i) {
		if (l[i]) a++;
	} cout << a << '\n';

	return 0;
}