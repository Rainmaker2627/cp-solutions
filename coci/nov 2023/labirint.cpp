#include<bits/stdc++.h>
using namespace std;
#define N 100

const vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m, q;
int e[N][N][4];
int g[N][N][15];
map<char, int> c;

void dfs(int x, int y, int p, int t) {
	g[x][y][p]=t;
	for (int i = 0; i < 4; ++i) {
		int a=x+moves[i].first, b=y+moves[i].second;
		if (a>=0 && a<n && b>=0 && b<m) {
			if (e[x][y][i]>0 && (p&(1<<c[e[x][y][i]]))>0 && g[a][b][p]==0) {
				dfs(a, b, p, t);
			}
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	c['P'] = 0; c['C'] = 1; c['Z'] = 2; c['N'] = 3;

	cin >> n >> m;
	char c;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m-1; ++j) {
			cin >> c;
			e[i][j][3]=e[i][j+1][2]=c;
		}
	}
	for (int i = 0; i < n-1; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> c;
			e[i][j][1]=e[i+1][j][0]=c;
		}
	}

	int t;
	for (int k = 1; k <= 15; ++k) {
		t=1;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (g[i][j][k]==0) {
					dfs(i, j, k, t);
					t++;
				}
			}
		}
	}

	cin >> q;
	for (int i = 0; i < q; ++i) {
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		a--; b--; c--; d--;
		int n=4;
		for (int j = 1; j <= 15; ++j) {
			if (g[a][b][j]==g[c][d][j]) n=min(n, __builtin_popcount(j));
		}
		cout << n << '\n';
	}

	return 0;
}