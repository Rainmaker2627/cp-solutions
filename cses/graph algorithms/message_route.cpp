#include<bits/stdc++.h>
using namespace std;

int n, m;
int p[200001];
vector<int> e[200001];

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}

	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto i : e[u]) {
			if (p[i]) continue;
			p[i]=u;
			q.push(i);
		}
	}

	if (p[n]!=0) {
		stack<int> s;
		int i=n;
		while (i!=1) { i=p[i]; s.push(i); }

		cout << s.size()+1 << '\n';
		while (!s.empty()) { cout << s.top() << ' '; s.pop(); }
		cout << n << '\n';
	} else {
		cout << "IMPOSSIBLE\n";
	}
	
	return 0;
}