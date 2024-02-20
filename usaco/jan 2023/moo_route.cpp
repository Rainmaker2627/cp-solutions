#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> p(n+1, 0), r;
	for (int i = 0; i < n; ++i) cin >> p[i];

	int i=0;
	while (!(p[i]==0 && i==0)) {
		while (p[i]>0) {
			r.push_back(1);
			p[i]--; i++;
		}
		while (i>0 && p[i]<=p[i-1]) {
			r.push_back(0);
			i--; p[i]--;
		}
	}

	for (auto i : r) cout << (i?'R':'L');
	return 0;
}