#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int m=2000;
	vector<int> dp(m+1, 0);
	for (int i = 3; i < m; ++i) {
		vector<int> g;
		for (int j = 1; j <= (i-1)/2; ++j) {
			g.push_back(dp[j]^dp[i-j]);
		} sort(g.begin(), g.end());
		int k=0;
		for (int j = 0; j < g.size(); ++j) {
			if (k<g[j]) break;
			if (k==g[j]) k++;
		} dp[i]=k;
	}


	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << (n<2000 && dp[n]==0?"second":"first") << '\n';
	}

	return 0;
}