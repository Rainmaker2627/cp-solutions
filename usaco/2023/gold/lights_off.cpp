#include<bits/stdc++.h>
using namespace std;

int n, m;
int cyc(int x) { return ((x&1)<<(n-1))+(x>>1); }
int bit(string s) {
	int r=0;
	for (int i = 0; i < n; ++i) {
		r+=(s[n-i-1]-'0')<<i;
	} return r;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int t;
	cin >> t >> n;
	m=1<<n;

	vector<int> rep(m, -1);
	for (int i = 0; i < m; ++i) {
		if (rep[i]==-1) {
			int t=i;
			while (rep[t]==-1) {
				rep[t]=i;
				t=cyc(t);
			}
		}
	}

	int cur=0;
	vector<vector<bool>> dp(3*n+1, vector<bool>(m, false));
	dp[0][0]=true;
	for (int i = 1; i <= 3*n; ++i) {
		cur^=1<<((i-1)%n);
		for (int j = 0; j < m; ++j) {
			if (!dp[i-1][rep[j]]) continue;
			dp[i][rep[cur^j]]=true;
		}
	}

	while (t--) {
		string x, y;
		cin >> x >> y;
		int a=bit(x), b=bit(y);
		int cur=0;
		for (int i = 0; i <= 3*n; ++i) {
			if (dp[i][rep[cur^a]]) {
				cout << i << '\n';
				break;
			} cur^=b;
			b=cyc(b);
		}
	}

	return 0;
}