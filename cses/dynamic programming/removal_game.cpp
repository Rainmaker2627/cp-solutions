#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 5001

int n;
ll x[N], dp[N][N];
bool v[N][N];

ll f(int l, int r) {
	if (l>r) return 0;
	if (v[l][r]) return dp[l][r];
	dp[l][r]=max(x[l]-f(l+1, r), x[r]-f(l, r-1));
	v[l][r]=true;
	return dp[l][r];
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	
	ll s=0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
		s+=x[i];
	}

	ll d=f(0, n-1);
	cout << (s+d)/2 << '\n';
	return 0;
}