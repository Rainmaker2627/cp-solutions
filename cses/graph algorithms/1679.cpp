#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> e(n+1, vector<int>());
	vector<int> in(n+1, 0);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		e[a].push_back(b);
		in[b]++;
	}

	queue<int> q, a;
	for (int i = 1; i <= n; ++i) {
		if (in[i]==0) {
			q.push(i); a.push(i);
		}
	} int u = q.size();
	while(!q.empty()) {
		int t = q.front();
		for (auto i : e[t]) {
			if (--in[i]==0) {
				q.push(i); a.push(i);
				u++;
			}
		} q.pop();
	}

	if (u==n) {
		while (a.size()>1) {
			cout << a.front() << ' ';
			a.pop();
		} cout << a.front() << '\n';
	} else cout << "IMPOSSIBLE\n";

	return 0;
}