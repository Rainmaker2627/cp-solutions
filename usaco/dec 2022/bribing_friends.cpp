#include<bits/stdc++.h>
using namespace std;
#define N 2001

int n, a, b;
int dp[N][2*N];

void set_max(int &a, int b) {
	if (b>a) a=b;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	
	cin >> n >> a >> b;
	vector<array<int, 3>> cows(n);
	for (auto &[x, p, c] : cows) {
		cin >> p >> c >> x;
	} sort(cows.begin(), cows.end());

	dp[0][a + b] = 0;
	for (int i = 0; i < n; ++i) {
		auto [x, p, c] = cows[i];
		for (int j = 0; j <= a+b; ++j) {
			set_max(dp[i+1][j], dp[i][j]);
			if (j-a >= c*x) {
				set_max(dp[i+1][j-c*x], dp[i][j]+p);
			} else if (j>a) {
				int t=c-(j-a)/x;
				if (a>=t) set_max(dp[i+1][a-t], dp[i][j]+p);
			} else if (j<=a && j>=c) {
				set_max(dp[i+1][j-c], dp[i][j]+p);
			} 
		}
	}

	int m=-1;
	for (int i = 0; i <= a+b; ++i) set_max(m, dp[n][i]);
	cout << m << '\n';
	
	return 0;
}