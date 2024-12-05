#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;

crope dfs(vector<vector<int>>& adj, int u=1, int p=1) {
	crope s="(";
	vector<crope> t;
	for (auto v : adj[u]) {
		if (v==p) continue;
		t.push_back(dfs(adj, v, u));
	} sort(t.begin(), t.end());
	for (auto i : t) s+=i;
	return s+=")";
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<vector<int>> a(n+1, vector<int>()), b(n+1, vector<int>());
		for (int i = 0; i < n-1; ++i) {
			int x, y;
			cin >> x >> y;
			a[x].push_back(y);
			a[y].push_back(x);
		}

		for (int i = 0; i < n-1; ++i) {
			int x, y;
			cin >> x >> y;
			b[x].push_back(y);
			b[y].push_back(x);
		}

		cout << (dfs(a)==dfs(b)?"YES\n":"NO\n");
	}

	return 0;
}