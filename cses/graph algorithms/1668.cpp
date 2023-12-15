#include<bits/stdc++.h>
using namespace std;

int n, m;
int c[200000];
vector<int> e[200000];

bool dfs(int u, int t) {
	if (c[u]==t) return true;
	else if (c[u]==(t^3)) return false;
	c[u]=t;
	for (auto i : e[u]) {
		if (!dfs(i, t^3)) return false;
	} return true;
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

	bool b=true;
	for (int i = 0; i < n; ++i) {
		if (c[i]==0) b&=dfs(i, 1);
	}

	if (b) {
		for (int i = 0; i < n-1; ++i) {
			cout << c[i] << ' ';
		} cout << c[n-1] << '\n';
	} else {
		cout << "IMPOSSIBLE\n";
	}
	return 0;
}