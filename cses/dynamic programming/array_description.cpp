#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1e9+7;
ll x[100000][102];
int n, m;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		if (i==0) {
			if (a>0) x[0][a]=1;
			else for (int j = 1; j < m+1; ++j) x[0][j]=1;
		} else {
			if (a>0) (x[i][a]+=x[i-1][a-1]+x[i-1][a]+x[i-1][a+1])%=mod;
			else {
				for (int j = 1; j < m+1; ++j) {
					(x[i][j]+=x[i-1][j-1]+x[i-1][j]+x[i-1][j+1])%=mod;
				}
			}
		}
	}

	int s=0;
	for (int i = 1; i < m+1; ++i) (s+=x[n-1][i])%=mod;
	cout << s << '\n';

	return 0;
}