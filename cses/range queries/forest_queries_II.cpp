#include<bits/stdc++.h>
using namespace std;

struct bit2d {
	int n, m;
	vector<vector<int>> bit;

	bit2d(vector<vector<int>>& a) {
		n=a.size();
		m=a[0].size();
		bit.assign(n+1, vector<int>(n+1, 0));
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (a[i-1][j-1]) update(i, j, 1);
			}
		}
	}

	void update(int x, int y, int v) {
		for (int i=x; i<=n; i+=i&-i) {
			for (int j=y; j<=m; j+=j&-j) {
				bit[i][j]+=v;
			}
		}
	}

	int query(int x,int y){
		int s=0;
		for (int i=x; i; i-=i&-i) {
			for (int j=y; j; j-=j&-j) {
				s+=bit[i][j];
			}
		}
		return s;
	}

};

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, q;
	cin >> n >> q;
	vector<vector<int>> c(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		for (int j = 0; j < n; ++j) {
			c[i][j]=(s[j]=='*');
		}
	}
	
	bit2d ft(c);
	for (int i = 0; i < q; ++i) {
		int t;
		cin >> t;
		if (t==1) {
			int x, y;
			cin >> x >> y;
			int q=ft.query(x,y)-ft.query(x-1,y)-ft.query(x,y-1)+ft.query(x-1,y-1);
			if (q) ft.update(x,y,-1);
			else ft.update(x,y,1);
		} else {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			cout << ft.query(x2,y2)-ft.query(x2,y1-1)-ft.query(x1-1,y2)+ft.query(x1-1,y1-1) << '\n'; 
		}
	}

	return 0;
}