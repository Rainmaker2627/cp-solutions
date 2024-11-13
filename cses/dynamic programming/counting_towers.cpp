#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 1000001

const int mod=1e9+7;
int t, n;
ll dp[N][2];

int main()  {
	cin.tie(0)->sync_with_stdio(false);

	dp[1][0]=1; dp[1][1]=1;
	for (int i = 2; i < N; ++i) {
		(dp[i][0]=2*dp[i-1][0]+dp[i-1][1])%=mod;
		(dp[i][1]=dp[i-1][0]+4*dp[i-1][1])%=mod;
	}

	cin >> t;
	while (t--) {
		cin >> n;
		cout << (dp[n][0]+dp[n][1])%mod << '\n';
	}

	return 0;
}