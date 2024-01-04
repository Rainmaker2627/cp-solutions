#include<bits/stdc++.h>
using namespace std;

int n;
int r[200000];

struct psn {
	int t, e, i;
	
	psn(int a, int b, int c) { t=a; e=b; i=c; }
	bool operator<(psn a) { return (t==a.t?e<a.e:t<a.t); }
};

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n;
	vector<psn> g;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		psn u(a, 0, i); g.push_back(u);
		psn v(b, 1, i); g.push_back(v);
	} sort(g.begin(), g.end());
	
	int m=0;
	queue<int> k;
	for (int i = 0; i < 2*n; ++i) {
		if (g[i].e) {
			k.push(r[g[i].i]);
		} else {
			if (k.empty()) k.push(++m);
			r[g[i].i]=k.front();
			k.pop();
		}
	}

	cout << m << '\n';
	for (int i = 0; i < n-1; ++i) {
		cout << r[i] << ' ';
	} cout << r[n-1] << '\n';

	return 0;
}