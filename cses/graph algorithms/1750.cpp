#include<bits/stdc++.h>
using namespace std;

int st[30][200005];

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> st[0][i];
	}

	for (int i = 1; i < 30; ++i) {
		for (int j = 1; j <= n; ++j) {
			st[i][j]=st[i-1][st[i-1][j]];
		}
	}

	while (q--) {
		int x, k;
		cin >> x >> k;
		for (int i = 0; i<30; ++i) {
			if (k&(1<<i)) x=st[i][x];
		} cout << x << '\n';
	}

	return 0;
}