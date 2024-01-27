#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> e(n+1, vector<int>());
	vector<int> in(n+1, 0), dp(n+1, 0);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		e[a].push_back(b);
		in[b]++;
	}

	queue<int> q; dp[1]=1;
	for (int i = 1; i <= n; ++i) if (in[i]==0) q.push(i);
	while (!q.empty()) {
		int t = q.front();
		for (auto i : e[t]) {
			if (--in[i]==0) q.push(i);
			(dp[i]+=dp[t])%=mod;
		} q.pop();
	}

	cout << dp[n] << '\n';
	return 0;
}