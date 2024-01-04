#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 5005

const int mod = 1e9+7;
ll dp[N][N], s[N];
int n, k;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	
	cin >> n >> k;

	dp[2][n-1]=2;
	for (int i = 3; i <= n; ++i) {
		s[n-1]=dp[i-1][n-1];
		for (int j = n-2; j > 0; --j) {
			s[j]=(dp[i-1][j]+s[j+2])%mod;
		}

		for (int j = n-2; j > 0; --j) {
			dp[i][j]=s[j+1];
			if (i+j<=n) (dp[i][j]+=s[i+j-1])%=mod;
		}
	}

	ll a=0;
	for (int i = 0; i <= min(n, k); ++i) {
		for (int j = 0; j < n; ++j) {
			(a+=(dp[i][j]*(k-i+1))%mod)%=mod;
		}
	}

	cout << a << '\n';
	return 0;
}