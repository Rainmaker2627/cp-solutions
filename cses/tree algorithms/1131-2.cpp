#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> e;
int v, m;

void dfs(int n, int p, int d) {
	if (d>m) { v=n; m=d; }
	for (auto u : e[n]) {
		if (u==p) continue;
		dfs(u, n, d+1);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	vector<vector<int>> s(n+1, vector<int>());
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		s[a].push_back(b);
		s[b].push_back(a);
	} swap(s, e);

	dfs(1, 1, 0); m=0;
	dfs(v, v, 0);
	cout << m << '\n';
	return 0;
}