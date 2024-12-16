#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> pii;

const int inf=1e18;

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int k, n, m, o, lg=0;
	cin >> k >> n >> m >> o;
	while (n>=(1<<lg)*k) lg++;
	vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(lg+1, vector<int>(k+1, inf)));
	for (int i = 0; i < m; ++i) {
		int a, b, t;
		cin >> a >> b >> t;
		dp[a][0][b%k]=t;
	}

	for (int f = (n-1)/k; f >= 0; --f) {
		for (int r1 = 0; r1 < k; ++r1) {
			if (f*k+r1>n) break;
			for (int j = 1; j < lg; ++j) {
				for (int r2 = 0; r2 < k; ++r2) {
					for (int r3 = 0; r3 < k; ++r3) {
						int t=dp[f*k+r1][j-1][r3];
						if (t!=inf) dp[f*k+r1][j][r2]=min(dp[f*k+r1][j][r2], t+dp[(f+(1<<(j-1)))*k+r3][j-1][r2]);
					}
				}
			}
		}
	}

	for (int i = 0; i < o; ++i) {
		int a, b;
		cin >> a >> b;
		if (a/k>=b/k) { cout << "-1\n"; continue; }

		vector<int> res(k, inf);
		res[a%k]=0; a/=k;
		for (int j = lg; j >= 0; --j) {
			if (b/k-a<(1<<j)) continue;
			vector<int> nxt(k, inf);
			for (int r2 = 0; r2 < k; ++r2) {
				if (res[r2]==inf) continue;
				for (int r3 = 0; r3 < k; ++r3) {
					nxt[r3]=min(nxt[r3], res[r2]+dp[a*k+r2][j][r3]);
				} 
			} swap(nxt, res);
			a+=(1<<j);
		} cout << (res[b%k]==inf?-1:res[b%k]) << '\n';
	}

	return 0;
}