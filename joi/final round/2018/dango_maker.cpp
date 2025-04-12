#include<bits/stdc++.h>
using namespace std;

vector<vector<char>> a;

bool dangoD (int i, int j) { return a[i-1][j]=='R' && a[i][j]=='G' && a[i+1][j]=='W'; }
bool dangoR (int i, int j) { return a[i][j-1]=='R' && a[i][j]=='G' && a[i][j+1]=='W'; }

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	a.assign(n+2, vector<char>(m+2, '#'));
	for (int i = 1; i <= n; ++i) {
		string s;
		cin >> s;
		for (int j = 1; j <= m; ++j) {
			a[i][j]=s[j-1];
		}
	}

	int res=0;
	vector<vector<int>> dp(n+1, vector<int>(3, 0));
	for (int t = 1; t <= n+m; ++t) {
		for (int i = 1; i <= n; ++i) {
			int j=t-i;
			if (j>m || j<=0) {
				for (int k = 0; k < 3; ++k) dp[i][k]=dp[i-1][k];
				continue;
			}
			dp[i][0]=max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]));
			dp[i][1]=max(dp[i-1][0], dp[i-1][1])+dangoR(i, j);
			dp[i][2]=max(dp[i-1][0], dp[i-1][2])+dangoD(i, j);
		} res+=max(dp[n][0], max(dp[n][1], dp[n][2]));
	} cout << res << '\n';

	return 0;
}