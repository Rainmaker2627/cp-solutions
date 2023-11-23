#include<bits/stdc++.h>
using namespace std;

int n, m;
char t[1002][1002];

void dfs(int i, int j) {
	t[i][j]='#';
	if (t[i-1][j]=='.') dfs(i-1, j);
	if (t[i+1][j]=='.') dfs(i+1, j);
	if (t[i][j-1]=='.') dfs(i, j-1);
	if (t[i][j+1]=='.') dfs(i, j+1);
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		t[0][i]=t[i][0]=t[n+1][i]=t[i][n+1]='#';
		for (int j = 1; j <= m; ++j) {
			cin >> t[i][j];
		}
	}

	int c=0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (t[i][j]=='.') {
				c++;
				dfs(i, j);
			}
		}
	}

	cout << c << '\n';
	return 0;
}