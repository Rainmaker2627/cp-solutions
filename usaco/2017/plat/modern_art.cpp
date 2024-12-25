#include<bits/stdc++.h>
using namespace std;

const int inf=1e9;
struct paint {
	bool s=false;
	int l=inf, r=-1, t=inf, b=-1;
	void upd(int i, int j) {
		s=true;
		l=min(l, i+1);
		r=max(r, i+1);
		t=min(t, j+1);
		b=max(b, j+1);
	}
};

int main() {
	ifstream fin("art.in");
	ofstream fout("art.out");

	int n, t=0;
	fin >> n;
	vector<paint> p(n*n+1);
	vector<vector<int>> art(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			fin >> art[i][j];
			if (art[i][j]==0) continue;
			if (!p[art[i][j]].s) t++;
			p[art[i][j]].upd(i, j);
		}
	}

	if (t==1) {
		fout << n*n-1 << '\n';
	} else {
		vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
		for (int i = 1; i <= n*n; ++i) {
			if (p[i].s) {
				dp[p[i].l][p[i].t]++;
				dp[p[i].r+1][p[i].t]--;
				dp[p[i].l][p[i].b+1]--;
				dp[p[i].r+1][p[i].b+1]++;
			}
		}

		int a=0;
		vector<bool> ok(n*n+1, true);
		for (int i = 1; i <= n+1; ++i) {
			for (int j = 1; j <= n+1; ++j) {
				dp[i][j]+=dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1];
				if (dp[i][j]>1 && ok[art[i-1][j-1]]) {
					ok[art[i-1][j-1]]=false; a++;
				}
			}
		} fout << n*n-a << '\n';
	}

	return 0;
}