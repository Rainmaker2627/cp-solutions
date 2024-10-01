#include<bits/stdc++.h>
using namespace std;
#define int long long
 
signed main() {
	cin.tie(0)->sync_with_stdio(false);
 
	int n, k;
	cin >> n >> k;
	vector<int> a(n+1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
 
	int lo=0, hi=1e18, cost;
	while (lo<hi) {
		int mid=(hi+lo)/2;
		vector<int> dp(n+1, 1e18), f(n+1, 0); dp[0]=0;
		for (int i = 1; i <= n; ++i) {
			int s=0;
			for (int j = i; j > 0; --j) {
				s+=a[j];
				int r=dp[j-1]+mid+s*s;
				if (r<=dp[i]) { dp[i]=r; f[i]=f[j-1]+1; }
			}
		}
 
		if (f[n]>k) lo=mid+1;
		else hi=mid, cost=dp[n]-mid*k;
	} cout << cost << '\n';
 
	return 0;
}