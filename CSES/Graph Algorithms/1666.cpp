#include<bits/stdc++.h>
using namespace std;

int n, m;
bool v[200000];
vector<int> e[200000];

void dfs(int u) {
	v[u]=true;
	for (auto i : e[u]) {
		if (!v[i]) dfs(i);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		e[--a].push_back(--b);
		e[b].push_back(a);
	}

	dfs(0);
	vector<int> s;
	for (int i = 1; i < n; ++i) {
		if (!v[i]) { s.push_back(i+1); dfs(i); }
	}

	cout << s.size() << '\n';
	for (auto i : s) { cout << 1 << ' ' << i << '\n'; }

	return 0;
}