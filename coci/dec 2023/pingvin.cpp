#include<bits/stdc++.h>
using namespace std;
#define N 100

struct coord {
	int x, y, z, w=0;

	void set(int a, int b, int c, int d) {
		x=a; y=b; z=c; w=d;
	}

	void dec() {
		x--; y--; z--;
	}
};

vector<vector<int>> moves = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
int vis[N][N][N];
bool cloud[N][N][N];

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	coord s, e;
	cin >> s.x >> s.y >> s.z >> e.x >> e.y >> e.z;
	s.dec(); e.dec();
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				char c;
				cin >> c;
				cloud[i][j][k]=(c=='1');
			}
		}
	}

	queue<coord> q;
	q.push(s);
	while (!q.empty()) {
		auto t = q.front();
		for (int i = 0; i < 6; ++i) {
			int a=t.x+moves[i][0], b=t.y+moves[i][1], c=t.z+moves[i][2];
			if (a>=0 && a<n && b>=0 && b<n && c>=0 && c<n && !cloud[a][b][c] && vis[a][b][c]==0) {
				vis[a][b][c]=t.w+1;
				coord p;
				p.set(a, b, c, t.w+1);
				q.push(p);
			}
		} q.pop();
	}

	if (s.x == e.x && s.y == e.y && s.z == e.z) cout << 0 << '\n';
	else cout << (vis[e.x][e.y][e.z]==0?-1:vis[e.x][e.y][e.z]) << '\n';
	return 0;
}