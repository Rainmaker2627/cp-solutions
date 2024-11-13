#include<bits/stdc++.h>
using namespace std;
#define int long long

struct project {
	int a, b, p;
	void init(int a, int b, int p) { this->a=a, this->b=b, this->p=p; }
	bool operator<(project c) { return (b==c.b?a<c.a:b<c.b); }
};

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> s;
	vector<project> p(n+1);
	for (int i = 1; i <= n; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		p[i].init(a, b, c);
		s.push_back(b);
	} sort(s.begin(), s.end());
	sort(p.begin(), p.end());

	vector<int> dp(n+1, 0);
	for (int i = 1; i <= n; ++i) {
		int x=lower_bound(s.begin(), s.end(), p[i].a)-s.begin();
		dp[i]=max(dp[i-1], p[i].p+dp[x]);
	} cout << dp[n] << '\n';

	return 0;
}