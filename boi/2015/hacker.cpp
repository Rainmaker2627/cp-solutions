#include<bits/stdc++.h>
using namespace std;

struct maxqueue {
	queue<int> q;
	deque<int> dq;

	void pop() {
		int v=q.front();
		if (v==dq.front()) dq.pop_front();
		q.pop();
	}

	void push(int v) {
		q.push(v);
		while (!dq.empty() && dq.back()<v) dq.pop_back();
		dq.push_back(v);
	}

	int query() {
		return dq.front();
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, c=0, t=0;
	cin >> n;
	vector<int> v(n), s(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		if (i<n/2) c+=v[i];
		t+=v[i];
	}

	maxqueue mq;
	for (int i = 0; i < n; ++i) {
		s[i]=c;
		if (i>0 && i<(n+1)/2+1) mq.push(s[i]);
		c+=v[(i+n/2)%n]-v[i];
	}

	int m=0;
	for (int i = 0; i < n; ++i) {
		m=max(m, t-mq.query());
		mq.pop();
		mq.push(s[(i+(n+1)/2+1)%n]);
	} cout << m << '\n';

	return 0;
}