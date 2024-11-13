#include<bits/stdc++.h>
using namespace std;

const int inf=1e9;
const vector<pair<int, int>> l = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m;
int d[1002][1002], e[1002][1002];
char p[1002][1002], r[1002][1002];

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> m;
	int a, b;
	queue<pair<int, int>> q;
	for (int i = 1; i <= n; ++i) {
		p[i][0]=p[0][i]=p[n+1][i]=p[i][n+1]='#';
		for (int j = 1; j <= m; ++j) {
			cin >> p[i][j];
			d[i][j]=inf;
			if (p[i][j]=='M') { q.push({i, j}); d[i][j]=0; }
			else if (p[i][j]=='A') { a=i, b=j; r[i][j]='S'; e[i][j]=0; }
		}
	}

	while (!q.empty()) {
		auto [i, j] = q.front();
		q.pop();
		for (auto [x, y] : l) {
			if (p[i+x][j+y]!='#' && d[i+x][j+y]==inf) {
				q.push({i+x, j+y});
				d[i+x][j+y]=d[i][j]+1;
			}
		}
	}

	bool t=false;
	q.push({a, b});
	while (!q.empty()) {
		auto [i, j] = q.front();
		if (i==n || i==1 || j==m || j==1) { t=true; break; }
		q.pop();
		for (auto [x, y] : l) {
			if (p[i+x][j+y]!='#' && r[i+x][j+y]==0 && d[i+x][j+y] > e[i][j]+1) {
				e[i+x][j+y]=e[i][j]+1;
				q.push({i+x, j+y});
				r[i+x][j+y]=(x==0?(y==1?'R':'L'):(x==1?'D':'U'));
			} 
		}
	}

	if (t) {
		cout << "YES\n";
		auto [i, j] = q.front();
		stack<char> s;

		while (r[i][j]!='S') {
			s.push(r[i][j]);
			switch(r[i][j]) {
				case 'R': j--; break;
				case 'L': j++; break;
				case 'U': i++; break;
				case 'D': i--; break;
			}
		}

		cout << s.size() << '\n';
		while (!s.empty()) {
			cout << s.top();
			s.pop();
		} cout << '\n';
	} else cout << "NO\n";

	return 0;
}