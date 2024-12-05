#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		v.push_back(v[i]);
	}

	int c=0;
	vector<vector<int>> s(19, vector<int>(n));
	for (int i = 0, j = 0; i < n; c-=v[i++]) {
		while (c<=k && j<=i+n) c+=v[j++];
		s[0][i]=j-i-1;
	}

	for (int j = 1; j < 19; ++j) {
		for (int i = 0; i < n; ++i) {
			int v=s[j-1][i];
			s[j][i]=s[j-1][(i+v)%n]+v;
		}
	}

	int m=n;
	for (int i = 0; i < n; ++i) {
		int q=0, l=n, c=i;
		for (int j = 18; j >= 0; --j) {
			if (s[j][c]<=l) {
				l-=s[j][c];
				c=(c+s[j][c])%n;
				q+=1<<j;
			}
		} m=min(m, q+(l>0));
	} cout << m << '\n';

	return 0;
}