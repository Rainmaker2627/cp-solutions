#include<bits/stdc++.h>
using namespace std;

int main() {
	int N, W;
	cin >> N >> W;
	vector<vector<int>> dp2(N+1, vector<int>(W+1, 0));
	vector<int> w(N), v(N), dp1(W+1, 0);
	for (int i = 0; i < N; ++i) {
		cin >> w[i] >> v[i];
	}

	for (int j = 0; j <= W; ++j) {
		for (int i = 1; i <= N; ++i) {
			if (j>=w[i-1]) dp1[j]=max(dp1[j], dp1[j-w[i-1]]+v[i-1]);
		}
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = W; j >= 0; --j) {
			dp2[i][j]=dp2[i-1][j];
			if (j>=w[i-1]) dp2[i][j]=max(dp2[i][j], dp2[i-1][j-w[i-1]]+v[i-1]);
		}
	}

	int a=0, b=0;
	for (int i = 0; i <= W; ++i) {
		a=max(a,dp1[i]); b=max(b,dp2[N][i]);
	}
	cout << a << ' ' << b << '\n';
	return 0;
}