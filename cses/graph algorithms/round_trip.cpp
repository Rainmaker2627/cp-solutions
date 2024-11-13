#include<bits/stdc++.h>
using namespace std;

int n, m;
bool v[200000];
vector<int> e[200000], c;

bool dfs(int u, int p) {
	if (v[u]) {
		c.push_back(u);
		return true;
	} else v[u]=true;
	for (auto i : e[u]) {
		if (i!=p && dfs(i, u)) { c.push_back(u); return true; }
	}
	return false;
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

	bool b=false;
	for (int i = 0; i < n && !b; ++i) {
		if (!v[i]) b=dfs(i, i);
	}

	if (b) {
		int s=c[0], d=0, t=0;
		for (auto i : c) {
			if (i==s) {
				if (t++==1) break;
			} d++;
		}

		cout << d+1 << '\n';
		for (int i = 0; i < d; ++i) {
			cout << c[i]+1 << ' ';
		} cout << c[d]+1 << '\n';
	} else cout << "IMPOSSIBLE\n";

	return 0;
}