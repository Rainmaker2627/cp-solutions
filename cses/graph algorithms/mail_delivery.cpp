#include<bits/stdc++.h>
using namespace std;

vector<int> ans;
vector<set<int>> e;

void dfs(int n) {
	while(!e[n].empty()) {
		auto t = *e[n].begin();
		e[n].erase(t);
		e[t].erase(n);
		dfs(t);
	} ans.push_back(n);
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	e.assign(n+1, set<int>());
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		e[a].insert(b);
		e[b].insert(a);
	}

	for (int i = 1; i <= n; ++i) {
		if (e[i].size()%2 == 1) {
			cout << "IMPOSSIBLE\n";
			return 0;
		}
	}

	dfs(1);
	if (ans.size() != m+1) {
		cout << "IMPOSSIBLE\n";
	} else {
		for (auto i : ans) {
			cout << i << ' ';
		} cout << '\n';
	}


    return 0;
}