#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;
int n;
long long dp[62626];

int main() {
	cin.tie(0)->sync_with_stdio(false);
	
	cin >> n;
	if ((n+1)%4>1) cout << 0 << '\n';
	else {
		int s=n*(n+1)/4; dp[0]=1;
		for (int i = 1; i <= n; ++i) {
			for (int j = s-i; j >= 0; --j) {
				(dp[j+i]+=dp[j])%=mod;
			}
		}

		cout << (dp[s]*500000004)%mod << '\n';
	}

	return 0;
}