/*

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll inf=1e18;
int n, m, q;
vector<pair<int, int>> e[500];
ll d[500][500];

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> m >> q;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			d[i][j]=(i==j?0:inf);
		}
	}
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		if (d[--a][--b]>c) d[a][b]=d[b][a]=c;
	}

	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
			}
		}
	}

	for (int i = 0; i < q; ++i) {
		int a, b;
		cin >> a >> b;
		cout << (d[a-1][b-1]==inf?-1:d[a-1][b-1]) << '\n';
	}

	return 0;
}