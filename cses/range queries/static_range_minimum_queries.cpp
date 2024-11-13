#include<bits/stdc++.h>
using namespace std;

int n, q;
long long x[200001];

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> q;
	int m=1;
	while ((1<<m)<n) m++;

	int sp[m][n];
	for (int i = 0; i < n; ++i) cin >> sp[0][i];
	for (int i = 1; i < m; ++i) {
		for (int j = 0; j <= n-(1<<i); ++j) {
			sp[i][j]=min(sp[i-1][j], sp[i-1][j+(1<<i-1)]);
		}
	}

	for (int i = 0; i < q; ++i) {
		int t=1, a, b;
		cin >> a >> b;
		while ((1<<t)<b-a+1) t++;
		cout << min(sp[t-1][a-1], sp[t-1][b-(1<<t-1)]) << '\n';
	}

	return 0;
}