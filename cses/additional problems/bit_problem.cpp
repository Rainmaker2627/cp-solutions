#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m=1e6+1;
	cin >> n;
	int lg=0;
	while ((1<<lg)<=m) lg++;
	m=1<<lg;

	vector<int> p(n), sub(m, 0), sup(m, 0), neu(m, 0);
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		sub[p[i]]++;
		sup[p[i]]++;
		neu[p[i]^(m-1)]++;
	}

	for (int i = 0; i < lg; ++i) {
		for (int j = 0; j < m; ++j) {
			if (j&(1<<i)) {
				sup[j^(1<<i)]+=sup[j];
				neu[j^(1<<i)]+=neu[j];
				sub[j]+=sub[j^(1<<i)];
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << sub[p[i]] << ' ' << sup[p[i]] << ' ' << n-neu[p[i]] << '\n';
	}

	return 0;
}