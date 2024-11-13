#include<bits/stdc++.h>
using namespace std;

const vector<int> pow10 = {1, 10, 100, 1000, 10000, 100000};
int n;

int digit(int n, int d) {
	return (n/pow10[d])%10;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	vector<int> dp(n+1, 1e9);
	dp[n]=0;
	if (n == 1e6) dp[--n]=1;
	for (int i = n; i >= 0; --i) {
		for (int j = 0; j < 6; ++j) {
			int d=digit(i,j);
			dp[i-d]=min(dp[i-d], dp[i]+1);
		}
	}
	
	cout << dp[0] << '\n';
	return 0;
}