#include<bits/stdc++.h>
using namespace std;
#define N 200001

vector<vector<int>> e(N, vector<int>());
vector<int> s(N, 0);

void dfs(int v) {
	bool c=false;
	for (auto i : e[v]) {
		c=true; dfs(i);
		s[v]+=s[i]+1;
	}
	if (!c) s[v]=0;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 2; i <= n; ++i) {
		int a;
		cin >> a;
		e[a].push_back(i);
	} dfs(1);

	for (int i = 1; i <= n; ++i) {
		cout << s[i] << (i==n?'\n':' ');
	}

	return 0;
}