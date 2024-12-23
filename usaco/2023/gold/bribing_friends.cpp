#include<bits/stdc++.h>
using namespace std;

struct cow {
	int p, c, x;
	cow(int _p, int _c, int _x) { p=_p, c=_c, x=_x; }
	bool operator<(cow b) { return x<b.x; }
};

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, a, b;
	cin >> n >> a >> b;
	vector<cow> q;
	for (int i = 0; i < n; ++i) {
		int p, c, x;
		cin >> p >> c >> x;
		q.emplace_back(p, c, x);
	} sort(q.begin(), q.end());

	vector<vector<int>> dp(n+1, vector<int>(a+b+1, 0));
	for (int i = 0; i < n; ++i) {
		auto [p, c, x]=q[i];
		for (int j = 0; j <= a+b; ++j) {
			dp[i+1][j]=max(dp[i+1][j], dp[i][j]);
			if (j+c*x<=b) {
				dp[i+1][j+c*x]=max(dp[i+1][j+c*x], dp[i][j]+p);
			} else if (j>=b && j+c<=a+b) {
				dp[i+1][j+c]=max(dp[i+1][j+c], dp[i][j]+p);
			} else if (j<b) {
				int t=(b-j)/x;
				if (c-t<=a) dp[i+1][b+c-t]=max(dp[i+1][b+c-t], dp[i][j]+p);
			}
		}
	}

	int m=-1;
	for (int i = 0; i <= a+b; ++i) m=max(dp[n][i], m);
	cout << m << '\n';

	return 0;
}