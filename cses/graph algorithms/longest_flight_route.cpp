#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	vector<vector<int>> e(n+1, vector<int>());
	vector<int> in(n+1, 0), dp(n+1, 0), r(n+1, 0);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		e[a].push_back(b);
		in[b]++;
	}

	queue<int> q; dp[1]=1; r[1]=1;
	for (int i = 1; i <= n; ++i) if (in[i]==0) { q.push(i); }
	while (!q.empty()) {
		int t = q.front();
		for (auto i : e[t]) {
			if (--in[i]==0) q.push(i);
			if (dp[t]+1>dp[i] && dp[t]) {
				dp[i]=dp[t]+1;
				r[i]=t;
			}
		} q.pop();
	}

	if (dp[n]) {
		stack<int> s;
		s.push(n);
		while (n!=r[n]) {
			n=r[n]; s.push(n);
		} cout << s.size() << '\n';
		while (!s.empty()) {
			cout << s.top() << (s.size()==1?'\n':' ');
			s.pop();
		}
	} else cout << "IMPOSSIBLE\n";

	return 0;
}