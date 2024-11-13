#include<bits/stdc++.h>
using namespace std;

vector<int> ans, v;

bool dfs(int n, vector<vector<int>>& e) {
	v[n]=2;
	for (auto i : e[n]) {
		if (v[i]==2) return false;
		else if (v[i]==0) {
			if (!dfs(i, e)) return false;
		}
	} v[n]=1;
	ans.push_back(n);
	return true;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> e(n+1, vector<int>());
	vector<int> t(n+1, 0); swap(v, t);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		e[a].push_back(b);
	}

	bool s=true;
	for (int i = 1; i <= n && s; ++i) {
		if (!v[i]) s&=dfs(i, e);
	}

	if (s) {
		for (int i = n-1; i >= 0; --i) {
			cout << ans[i] << (i?' ':'\n');
		}
	} else cout << "IMPOSSIBLE\n";

	return 0;
}