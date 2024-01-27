#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> e;
int t, q;

void dfs(int u, int p, vector<int>& d) {
	d[u]=d[p]+1;
	if (d[u]>t) { t=d[u]; q=u; }
	for (auto v : e[u]) {
		if (v==p) continue;
		dfs(v, u, d);
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

	int x, y;
	vector<int> a(n+1, 0), b(n+1, 0);
	a[0]=b[0]=-1; t=q=0;
	dfs(1, 0, a); x=q; t=q=0;
	dfs(x, 0, a); y=q;
	dfs(y, 0, b);

	for (int i = 1; i <= n; ++i) {
		cout << max(a[i], b[i]) << ' ';
	}

	return 0;
}