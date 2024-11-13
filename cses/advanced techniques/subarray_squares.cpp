#include<bits/stdc++.h>
using namespace std;
#define int long long

struct line {
	int m, c;
	int operator[](int x) {
		return m*x+c;
	}
};

bool useless(line l1, line l2, line l3) {
	return (l1.c-l3.c)*(l2.m-l1.m)<=(l1.c-l2.c)*(l3.m-l1.m);
}

struct cht {
	deque<line> dq;
	int query(int x) {
		while (dq.size()>1 && dq[0][x]>dq[1][x]) dq.pop_front();
		return dq.front()[x];
	}

	void add(line l) {
		while (dq.size()>1 && useless(dq[dq.size()-2], dq.back(), l)) dq.pop_back();
		dq.push_back(l);
	}
};

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<int> pre(n+1);
	vector<vector<int>> dp(n+1, vector<int>(2, 0));
	for (int i = 1; i <= n; ++i) {
		cin >> pre[i];
		pre[i]+=pre[i-1];
		dp[i][0]=pre[i]*pre[i];
	}

	cht lines;
	for (int j = 1; j < k; ++j) {
		lines.dq.clear();
		lines.add({-2*pre[j-1], dp[j-1][(j-1)%2]+pre[j-1]*pre[j-1]});
		for (int i = j; i <= n; ++i) {
			dp[i][j%2]=pre[i]*pre[i]+lines.query(pre[i]);
			lines.add({-2*pre[i], dp[i][(j-1)%2]+pre[i]*pre[i]});
		}
	}

	cout << dp[n][(k-1)%2] << '\n';
	return 0;
}