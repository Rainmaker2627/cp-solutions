#include<bits/stdc++.h>
using namespace std;

int n, m;
int row(vector<int>& v) {
	int t=0;
	stack<int> s, h;
	s.push(0); h.push(0);
	for (int i = 0; i <= m; ++i) {
		int p=i;
		while (h.top()>v[i]) {
			p=s.top();
			t=max(t, (i-p)*h.top());
			s.pop(); h.pop();
		} s.push(p); h.push(v[i]);
	} return t;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m+1, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char c;
			cin >> c;
			v[i][j]=(c=='.');
		}
	}

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (v[i][j]==0) continue;
			v[i][j]+=v[i-1][j];
		}
	}

	int t=0;
	for (int i = 0; i < n; ++i) {
		t=max(t, row(v[i]));
	} cout << t << '\n';

	return 0;
}