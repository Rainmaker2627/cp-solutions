#include<bits/stdc++.h>
using namespace std;

int p;
vector<int> s;
vector<set<int>> e;

void dfs(int n) {
	while (!e[n].empty()) {
		auto t=*e[n].begin();
		e[n].erase(t);
		dfs(t);
	} s.push_back(n&1);
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;

	if (n==1) {
		cout << "10\n";
		return 0;
	}

	p=1<<(n-1);
	e.assign(p, set<int>());
	for (int i = 0; i < p; ++i) {
		e[i].insert((i<<1)%p);
		e[i].insert(((i<<1)+1)%p);
	}

	dfs(0);
	for (auto i : s) cout << i;
	for (int i = 0; i < n-2; ++i) cout << 0;
	cout << '\n';

	return 0;
}