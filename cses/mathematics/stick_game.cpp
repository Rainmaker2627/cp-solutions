#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<int> p(k), dp(n+1, 0);
	for (int i = 0; i < k; ++i) {
		cin >> p[i];
		dp[p[i]]=1;
	}

	for (int i = 1; i <= n; ++i) {
		if (dp[i]) {
			cout << 'W';
		} else {
			cout << 'L';
			for (int j = 0; j < k; ++j) {
				if (i+p[j]<=n) dp[i+p[j]]=1;
			}
		}
	} cout << '\n';


	return 0;
}