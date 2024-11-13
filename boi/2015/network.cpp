#include<bits/stdc++.h>
using namespace std;

vector<int> l;
vector<vector<int>> g;

void dfs(int u, int p) {
	if (g[u].size()==1) l.push_back(u);
	for (auto v : g[u]) {
		if (v==p) continue;
		dfs(v, u);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, k;
	cin >> n;
	g.assign(n+1, vector<int>());
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs(1, 1);
	cout << (k=l.size()+1)/2 << '\n';
	for (int i = 0; i < k/2; ++i) {
		cout << l[i] << ' ' << l[i+(k-1)/2] << '\n';
	}

	return 0;
}