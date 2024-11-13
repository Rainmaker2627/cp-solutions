#include<bits/stdc++.h>
using namespace std;

vector<int> mt;
vector<bool> used;
vector<vector<int>> g;

bool match(int v) {
	if (used[v]) return false;
	used[v]=true;
	for (auto i : g[v]) {
		if (mt[i]==-1 || match(mt[i])) {
			mt[i]=v;
			return true;
		}
	}
	return false;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;
	g.assign(n+1, vector<int>());
	for (int i = 0; i < k; ++i) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
	}

	mt.assign(m+1, -1);
	for (int i = 1; i <= n; ++i) {
		used.assign(n+1, false);
		match(i);
	}

	int x=0;
	for (int i = 1; i <= m; ++i) {
		if (mt[i]==-1) continue;
		x++;
	} cout << x << '\n';
	
	for (int i = 1; i <= m; ++i) {
		if (mt[i]==-1) continue;
		cout << mt[i] << ' ' << i << '\n';
	}

	return 0;
}