#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll inf = 1e18;
int n, m;
vector<pair<int, int>> f[2500];
ll e[5000][3], d[2500];

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> e[i][0] >> e[i][1] >> e[i][2];
		f[--e[i][0]].push_back({--e[i][1], e[i][2]});
	}

	for (int i = 1; i < n; ++i) d[i]=inf; 

	int t;
	for (int i = 0; i <= n; ++i) {
		t=-1;
		for (int j = 0; j < m; ++j) {
			if ([e[j][1]]>d[e[j][0]]+d[e[j][2]]) {
				d[e[j][1]]=d[e[j][0]]+d[e[j][2]];
				t=e[j][0];
			}
		}
	}

	if (t>-1) {
		cout << "YES\n";
		// Do a BFS lol
	} else cout << "NO\n";

	return 0;
}