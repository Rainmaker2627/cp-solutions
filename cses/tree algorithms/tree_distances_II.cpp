#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;
vector<vector<int>> e;
vector<int> p, s, a;

void dfsa(int u, int v) {
	for (auto i : e[u]) {
		if (i==v) continue;
		dfsa(i, u);
		s[u]+=s[i];
		p[u]+=p[i]+s[i];
	}
}

void dfsb(int u, int v) {
	if (u!=v) a[u]=a[v]+n-2*s[u];
	for (auto i : e[u]) {
		if (i==v) continue;
		dfsb(i, u);
	}
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n;
	p.assign(n+1, 0); s.assign(n+1, 1); a.assign(n+1, 0);
	e.assign(n+1, vector<int>());
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}

	dfsa(1, 1); a[1]=p[1]; dfsb(1, 1);
	for (int i = 1; i <= n; ++i) {
		cout << a[i] << ' ';
	}

	return 0;
}