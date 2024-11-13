#include <bits/stdc++.h>
using namespace std;
#define int long long

const int inf = 1e18;
vector<vector<int>> dp;
vector<vector<pair<int, int>>> adj;

void dfs(int u, int p) {
	int mx0=0, mx1=0;
	pair<int, int> mxb[2]={{-inf, 0}, {-inf, 0}};
	pair<int, int> mxr[2]={{-inf, 0}, {-inf, 0}};
	for (auto& [v, w] : adj[u]) {
		if (v==p) continue;
		dfs(v, u);
		int val=max(dp[v][1], dp[v][2]+w);
		dp[u][0]+=val;
		dp[u][1]+=val;
		dp[u][2]+=val;
		dp[u][3]+=val;
		mx0=max(mx0, max(dp[v][0], dp[v][3]+w)-val);
		mxr[1] = max(mxr[1], {dp[v][1]+w-val, v});
		mxb[1] = max(mxb[1], {dp[v][0]+w-val, v});
		if (mxr[0] < mxr[1]) swap(mxr[0], mxr[1]);
		if (mxb[0] < mxb[1]) swap(mxb[0], mxb[1]);
	}
	if (mxr[0].second != mxb[0].second) mx1=mxr[0].first+mxb[0].first;
	else mx1 = max(mxr[0].first + mxb[1].first, mxr[1].first + mxb[0].first);
	dp[u][0]+=max(mx1, mx0);
	dp[u][2]+=mxr[0].first;
	dp[u][3]+=mxb[0].first;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	adj.assign(n+1, vector<pair<int, int>>());
	for (int i = 1; i < n; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}

	dp.assign(n+1, vector<int>(4, 0));
	dfs(1, 1);
	cout << max(dp[1][0], dp[1][1]) << '\n';

	return 0;
}