#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int m=1e6+1;
	vector<int> pr, lp(m, 0), mu(m, 1);
	for (int i = 2; i < m; ++i) {
		if (lp[i]==0) {
			pr.push_back(i);
			lp[i]=i;
			mu[i]=-1;
		}
		for (int j = 0; i*pr[j] < m; ++j) {
			lp[i*pr[j]]=pr[j];
			if (pr[j]==lp[i]) {
				mu[i*pr[j]]=0;
				break;
			} else {
				mu[i*pr[j]]=mu[i]*mu[pr[j]];
			}
		}
	}

	int n;
	cin >> n;
	vector<int> x(m, 0);
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		x[t]++;
	}

	int s=0;
	for (int i = 1; i < m; ++i) {
		int c=0;
		if (mu[i]==0) continue;
		for (int j = i; j < m; j+=i) c+=x[j];
		s+=mu[i]*c*(c-1)/2;
	}

	cout << s << '\n';
	return 0;
}