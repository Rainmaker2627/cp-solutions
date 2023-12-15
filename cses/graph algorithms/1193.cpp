#include<bits/stdc++.h>
using namespace std;

int n, m;
char t[1002][1002];

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> m;
	int a, b, c, d;
	for (int i = 1; i <= n; ++i) {
		t[0][i]=t[i][0]=t[n+1][i]=t[i][n+1]='#';
		for (int j = 1; j <= m; ++j) {
			cin >> t[i][j];
			if (t[i][j]=='A') { a=i, b=j; t[i][j]='.'; }
			else if (t[i][j]=='B') { c=i, d=j; t[i][j]='.'; }
		}
	}

	queue<pair<int, int>> q;
	q.push({a, b});
	while (!q.empty()) {
		auto [i, j] = q.front();
		q.pop();
		if (i==c && j==d) break;
		if (t[i-1][j]=='.') { t[i-1][j]='U'; q.push({i-1, j}); }
		if (t[i+1][j]=='.') { t[i+1][j]='D'; q.push({i+1, j}); }
		if (t[i][j-1]=='.') { t[i][j-1]='L'; q.push({i, j-1}); } 
		if (t[i][j+1]=='.') { t[i][j+1]='R'; q.push({i, j+1}); }
	}

	if (t[c][d]!='.') {
		cout << "YES\n";
		stack<char> s;
		while (c!=a || d!=b) {
			s.push(t[c][d]);
			if (t[c][d]=='U') { c++; }
			else if (t[c][d]=='D') { c--; }
			else if (t[c][d]=='L') { d++; } 
			else if (t[c][d]=='R') { d--; }
		}

		cout << s.size() << '\n';
		while(!s.empty()) {
			cout << s.top();
			s.pop();
		} cout << '\n';
	} else {
		cout << "NO\n";
	}

	return 0;
}