#include<bits/stdc++.h>
using namespace std;
#define N 3005

const int inf = 1e9;
int n, c;
int a[N], L[N], R[N];
int dp[N][N];

bool used(int l, int r, int c) {
	return l<=L[c] && r>=R[c];
}

int f(int l, int r) {
	if (l>r) return 0;
	if (dp[l][r]<inf) return dp[l][r];
	return dp[l][r]=max(used(l,r,a[l])-f(l+1, r), used(l,r,a[r])-f(l, r-1));
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (L[a[i]]==0) { L[a[i]]=i; c++; }
		else R[a[i]]=i;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			dp[i][j]=inf;
		}
	}

	int p=(c+f(1, n))/2;
	cout << p << ':' << c-p << '\n';
	// cin >> n;
	return 0;
}