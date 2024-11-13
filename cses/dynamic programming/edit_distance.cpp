#include<bits/stdc++.h>
using namespace std;
#define N 5002

const int inf = 1e9;
string a, b;
int dp[N][N];

int main() {
	cin.tie(0)->sync_with_stdio(false);

	string a, b;
	cin >> a >> b;
	for (int i = 0; i <= a.size(); ++i) {
		for (int j = 0; j <= b.size(); ++j) {
			dp[i][j]=inf;
		}
	}

	dp[0][0]=0;
	for (int i = 0; i <= a.size(); ++i) {
		for (int j = 0; j <= b.size(); ++j) {
			dp[i+1][j]=min(dp[i+1][j], dp[i][j]+1);
			dp[i][j+1]=min(dp[i][j+1], dp[i][j]+1);
			dp[i+1][j+1]=min(dp[i+1][j+1], dp[i][j]+(a[i]!=b[j]));
		}
	}

	cout << dp[a.size()][b.size()] << '\n';
	return 0;
}