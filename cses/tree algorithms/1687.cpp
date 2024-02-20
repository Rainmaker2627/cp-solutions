#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, q;
	cin >> n >> q;
	vector<vector<int>> p(21, vector<int>(n+1, -1));
	for (int i = 2; i <= n; ++i) {
		cin >> p[0][i];
	}

	for (int i = 1; i <= 20; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (p[i-1][j]==-1) p[i][j]=-1;
			else p[i][j]=p[i-1][p[i-1][j]];
		}
	}

	for (int i = 0; i < q; ++i) {
		int x, k;
		cin >> x >> k;
		for (int j = 0; j < 20 && x>0; ++j) {
			if (k&(1<<j)) x=p[j][x];
		} cout << x << '\n';
	}

	return 0;
}