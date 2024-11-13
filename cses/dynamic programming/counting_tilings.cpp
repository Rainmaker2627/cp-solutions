#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	
	int s=1<<n;
	vector<vector<int>> rs(s, vector<int>());
	for (int i = 0; i < s; ++i) {
		rs[i].push_back( (~i)&(s-1) );
		for (int j = n-1; j > 0; j--) {
			int t = rs[i].size();
			for (int k = 0; k < t; ++k) {
				if ( ((~rs[i][k])&(3<<(j-1))) ) continue;
				rs[i].push_back( (rs[i][k]-(3<<(j-1)))&(s-1) );
			}
		}
	}

	vector<vector<int>> dp(m+1, vector<int>(s, 0)); dp[0][0]=1;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < s; ++j) {
			if (dp[i][j]==0) continue;
			for (auto k : rs[j]) {
				dp[i+1][k]=(dp[i+1][k]+dp[i][j])%mod;
			}
		}
	}

	cout << dp[m][0] << '\n';
	return 0;
}