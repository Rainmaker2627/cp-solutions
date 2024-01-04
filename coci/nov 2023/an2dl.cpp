#include<bits/stdc++.h>
using namespace std;
#define N 4000

int n, m, r, s;
int a[N][N], b[N][N], c[N][N];

struct max_queue {
	queue<int> q;
	deque<int> dq;

	void push(int a) {
		while (!dq.empty() && dq.back()<a) dq.pop_back();
		dq.push_back(a);
		q.push(a);
	}

	void pop() {
		if (q.front()==dq.front()) dq.pop_front();
		q.pop();
	}

	int get_max() {
		return dq.front();
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(false);
	
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	} cin >> r >> s;

	for (int i = 0; i < n; ++i) {
		max_queue q;
		for (int j = 0; j < s-1; ++j) q.push(a[i][j]);
		for (int j = 0; j < m-s+1; ++j) {
			q.push(a[i][j+s-1]);
			b[i][j]=q.get_max();
			q.pop();
		}
	} for (int j = 0; j < m-s+1; ++j) {
		max_queue q;
		for (int i = 0; i < r-1; ++i) q.push(b[i][j]);
		for (int i = 0; i < n-r+1; ++i) {
			q.push(b[i+r-1][j]);
			c[i][j]=q.get_max();
			q.pop();
		}
	}

	for (int i = 0; i < n-r+1; ++i) {
		for (int j = 0; j < m-s+1; ++j) {
			cout << c[i][j] << ' ';
		} cout << '\n';
	}

	return 0;
}