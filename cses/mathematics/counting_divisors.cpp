#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n=1e6+1;
	vector<int> pr, lp(n, 0);
	for (int i = 2; i < n; ++i) {
		if (lp[i]==0) {
			lp[i]=i;
			pr.push_back(i);
		}
		for (int j = 0; i*pr[j] < n; ++j) {
			lp[i*pr[j]]=pr[j];
			if (lp[i]==pr[j]) break;
		}
	}

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		int p=lp[x], c=1, d=1;
		while (x>1) {
			x=x/p;
			if (lp[x]==p) c++;
			else d=d*(c+1), c=1, p=lp[x];
		} cout << d << '\n';
	}

	return 0;
}