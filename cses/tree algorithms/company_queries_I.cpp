#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, q;
	cin >> n >> q;

	int m=0;
	while (n>=(1<<m)) m++;

	vector<vector<int>> par(m+1, vector<int>(n+1, 0));
	for (int i = 2; i <= n; ++i) {
		cin >> par[0][i];
	}

	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j <= n; ++j) {
			par[i][j]=par[i-1][par[i-1][j]];
		}
	}

	for (int i = 0; i < q; ++i) {
		int x, k;
		cin >> x >> k;
		for (int j = m; j >= 0; --j) {
			if ((1<<j)<=k) {
				x=par[j][x];
				k-=1<<j;
			}
		}
		cout << (x?x:-1) << '\n';
	}

	return 0;
}