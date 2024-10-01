#include<bits/stdc++.h>
using namespace std;
#define int long long

struct max_queue {
	queue<int> q;
	deque<int> dq;

	void push(int v) {
		while (!dq.empty() && v>dq.back()) dq.pop_back();
		dq.push_back(v);
		q.push(v);
	}

	void pop() {
		if (q.front()==dq.front()) dq.pop_front();
		q.pop();
	}

	int max() {
		return dq.front();
	}
};

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	max_queue q;
	int n, a, b;
	cin >> n >> a >> b;
	vector<int> x(n+1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> x[i]; x[i]+=x[i-1];
		if (a<=i && i<=b) q.push(x[i]);
	}

	int m=-1e18;
	for (int i = 1; i <= n-a+1; ++i) {
		m=max(m, q.max()-x[i-1]);
		if (i+b<=n) q.push(x[i+b]);
		q.pop();
	} cout << m << '\n';

	return 0;
}