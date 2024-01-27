#include<bits/stdc++.h>
using namespace std;
#define N 200001

const int inf=1e9;
vector<vector<int>> e(N, vector<int>()), dp(N, vector<int>(2, 0));

void dfs(int u, int p) {
	int a=0, b=0;
	dp[u][1]=-inf;
	for (auto v : e[u]) {
		if (v==p) continue;
		dfs(v, u);
		dp[u][0]+=max(dp[v][0], dp[v][1]);
		dp[u][1]=max(dp[u][1], 1+dp[v][0]-max(dp[v][0], dp[v][1]));
	} dp[u][1]+=dp[u][0];
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}

	dfs(1, 0);
	cout << max(dp[1][0], dp[1][1]) << '\n';
	return 0;
}