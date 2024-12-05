#include<bits/stdc++.h>
using namespace std;

int t=0;
vector<vector<int>> q;
void count(int m=0, int n=0, int c=0) {
	if (m==8) return;
	if (q[m][n]==-1) { count((8*m+n+1)/8, (8*m+n+1)%8, c); return; }
	bool p=false;
	for (int i = m; i >= 0; --i) p|=(q[i][n]==1);
	for (int i = n; i >= 0; --i) p|=(q[m][i]==1);
	for (int i = min(m, n); i >= 0; --i) p|=(q[m-i][n-i]==1);
	for (int i = min(m, 7-n); i >= 0; --i) p|=(q[m-i][n+i]==1);
	if (p) count((8*m+n+1)/8, (8*m+n+1)%8, c);
	else {
		if (c<7) { q[m][n]=1; count((8*m+n+1)/8, (8*m+n+1)%8, c+1); }
		else t++;
		q[m][n]=0; count((8*m+n+1)/8, (8*m+n+1)%8, c);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	q.assign(8, vector<int>(8, 0));
	for (int i = 0; i < 8; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < 8; ++j) {
			q[i][j]=(s[j]=='.'?0:-1);
		}
	}

	count();
	cout << t << '\n';

	return 0;
}