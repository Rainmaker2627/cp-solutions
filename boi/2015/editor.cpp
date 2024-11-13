#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> e(n+1, 0), r; r.push_back(0);
	vector<vector<int>> p(20, vector<int>(n+1, 0)), m(20, vector<int>(n+1, 0));
	for (int i = 1; i <= n; ++i) {
		cin >> e[i];
		if (e[i]>0) {
			r.push_back(e[i]);
			p[0][i]=i;
		} else {
			int c=i-1;
			for (int j = 19; j >= 0; --j) {
				if (m[j][c]<=e[i]) c=p[j][c];
			} r.push_back(r[c-1]);
			p[0][i]=c-1;
			m[0][i]=e[i];
			for (int j = 1; j < 20; ++j) {
				p[j][i]=p[j-1][p[j-1][i]];
				m[j][i]=max(m[j-1][i], m[j-1][p[j-1][i]]);
			}
		}
	}

	for (int i = 1; i <= n; ++i) cout << r[i] << ' ';
	return 0;
}