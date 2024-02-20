#include<bits/stdc++.h>
using namespace std;
#define int long long

int days(int n, int m, int x) {
	int k=0, g=0;
	while (g<n) {
		int f=(n-g)/x;
		if (f>m) {
			int t=((n-g)%x-1)/f;
			k+=t+1; g+=f*(t+1);
		} else {
			k+=(n-g-1)/m+1;
			break;
		}
	} return k;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);
	ifstream fin("loan.in");
	ofstream cout("loan.out");

	int n, k, m;
	fin >> n >> k >> m;

	int hi=k, lo=1;
	while (lo<hi) {
		int mid=(hi+lo)/2;
		if (days(n, m, mid)<=k) lo=mid+1;
		else hi=mid;
	} cout << hi-1 << '\n';

	return 0;
}