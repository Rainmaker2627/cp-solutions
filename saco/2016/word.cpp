#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int k;
	string s;
	cin >> s >> k;
	vector<int> x(s.size());
	for (int i = 0; i < s.size(); ++i) x[i]=s[i]-'a';

	int n;
	cin >> n;
	vector<vector<int>> m(26, vector<int>(26, 0));
	for (int i = 0; i < n; ++i) {
		char a, b;
		int c;
		cin >> a >> b >> c;
		m[a-'a'][b-'a']=c;
	}

	vector<vector<vector<int>>> dp(s.size()+1, vector<vector<int>>(26, vector<int>(k+1, -inf)));
	dp[0][x[0]][0]=0;
	for (int i = 1; i < s.size(); ++i) {
		dp[i][x[i]][0]=dp[i-1][x[i-1]][0]+m[x[i-1]][x[i]];
	}

	for (int i = 1; i <= k; ++i) {
		for (int a = 0; a < 26; ++a) dp[0][a][i]=0;
		for (int j = 1; j < s.size(); ++j) {
			dp[j][x[j]][i]=dp[j][x[j]][i-1];
			for (int a = 0; a < 26; ++a) {
				dp[j][x[j]][i]=max(dp[j][x[j]][i], dp[j-1][a][i]+m[a][x[j]]);
				for (int b = 0; b < 26; ++b) {
					dp[j][b][i]=max(dp[j][b][i], dp[j-1][a][i-1]+m[a][b]);
				}
			}
		}
	}

	int r=-inf;
	for (int i = 0; i < 26; ++i) {
		r=max(r, dp[s.size()-1][i][k]);
	} cout << r << '\n';

	return 0;
}