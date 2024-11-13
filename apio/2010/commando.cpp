#include<bits/stdc++.h>
using namespace std;
#define int long long

const int inf=1e18;

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, a, b, c;
	cin >> n >> a >> b >> c;
	vector<int> pre(n+1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> pre[i];
		pre[i]+=pre[i-1];
	}

	deque<pair<int, pair<int, int>>> s;
	s.push_back({inf, {0, 0}});
	vector<int> dp(n+1, 0);
	for (int i = 1; i <= n; ++i) {
		dp[i]=(a*pre[i]+b)*pre[i]+c;
		while (pre[i]>s.front().first) s.pop_front();
		auto [m, c] = s.front().second;
		dp[i]+=m*pre[i]+c;
		int mn=-2*a*pre[i], cn=(a*pre[i]-b)*pre[i]+dp[i];
		while (!s.empty()) {
			auto [m, c] = s.back().second;
			int x = (cn-c)/(m-mn);
			s.pop_back();
			if (s.empty() || x>s.back().first) { s.push_back({x, {m, c}}); break; }
		} s.push_back({inf, {mn, cn}});
	}

	cout << dp[n] << '\n';
	return 0;
}