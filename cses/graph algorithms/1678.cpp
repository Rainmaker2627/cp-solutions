#include<bits/stdc++.h>
using namespace std;

vector<int> ans, v;

int dfs(int n, vector<vector<int>>& e) {
	if (v[n]==2) {
		ans.push_back(n);
		return 1;
	} else if (v[n]==1) return 0;
	v[n]=2;
	for (auto i : e[n]) {
		int r=dfs(i, e);
		if (r==1) {
			ans.push_back(n);
			if (n==ans[0]) return 2;
			else return 1;
		} else if (r==2) return 2;
	} v[n]=1;
	return 0;
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

	bool b=false;
	for (int i = 1; i <= n && !b; ++i) {
		if (!v[i] && dfs(i, e)) b=true;
	}

	if (b) {
		cout << ans.size() << '\n';
		for (int i = ans.size()-1; i >= 0; --i) {
			cout << ans[i] << (i?' ':'\n');
		}
	} else cout << "IMPOSSIBLE\n";

	return 0;
}