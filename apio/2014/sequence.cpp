#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll inf=1e18;

struct line {
	ll m, c, id;
	ll operator[](ll x) {
		return m*x+c;
	}
};

struct cht {
	deque<line> dq;
	ll query(ll x) {
		while (dq.size()>1 && dq[1][x]>dq[0][x]) dq.pop_front();
		return dq.front()[x];
	}

	void add(line l) {
		ll n=dq.size();
		while (dq.size()>1 && (l.c-dq[n-2].c)*(dq[n-2].m-dq[n-1].m)<=(dq[n-1].c-dq[n-2].c)*(dq[n-2].m-l.m)) {
			n--; dq.pop_back();
		} dq.push_back(l);
	}

	void clear() {
		dq.clear();
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<ll> pre(n+1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> pre[i];
		pre[i]+=pre[i-1];
	}

	cht lines;
	vector<vector<ll>> dp(n+1, vector<ll>(2, 0));
	vector<vector<int>> prev(n+1, vector<int>(k+1, 0));
	for (int j = 1; j <= k; ++j) {
		lines.clear();
		lines.add({pre[j-1], dp[j-1][(j-1)%2]-pre[n]*pre[j-1], j-1});
		for (int i = j; i <= n; ++i) {
			dp[i][j%2]=pre[i]*(pre[n]-pre[i])+lines.query(pre[i]);
			prev[i][j]=lines.dq.front().id;
			lines.add({pre[i], dp[i][(j-1)%2]-pre[n]*pre[i], i});
		}
	}

	ll m=-1, j=0;
	for (int i = 1; i <= n; ++i) {
		if (dp[i][k%2]>m) m=dp[i][k%2], j=i;
	} cout << m << '\n';

	cout << j;
	for (int i = 0; i < k-1; ++i) {
		j=prev[j][k-i];
		cout << ' ' << j;
	} cout << '\n';

	return 0;
}