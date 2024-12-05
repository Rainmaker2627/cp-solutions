#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define fi first
#define sc second

int n, d;
vector<vector<int>> adj;

pii dfs(int u) {
	pii ans={1, 0};
	for (auto v : adj[u]) {
		pii ch=dfs(v);
		ans.fi+=ch.fi;
		if (ans.sc+ch.sc+1<d) {
			ans={ans.fi-1, max(ans.sc, ch.sc+1)};
		} else ans.sc=min(ans.sc, ch.sc+1);
	} return ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> d;
	adj.assign(n+1, vector<int>());
	for (int i = 1; i < n; ++i) {
		int a;
		cin >> a;
		adj[a].push_back(i);
	}

	cout << dfs(0).first << '\n';
	return 0;
}