#include<bits/stdc++.h>
using namespace std;

int n, x;
vector<pair<int, int>> a;

int find(int t) {
	int s=0, e=n;
	while (s<e) {
		int m=(s+e)/2;
		if (a[m].first <= t) s=m+1;
		else e=m;
	}
	if (a[s-1].first == t) return a[s-1].second;
	else return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> x;
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		a.push_back({t, i});
	} sort(a.begin(), a.end());

	int i=0, t=-1;
	while (i <= n && 2*a[i].first<=x) {
		t=find(x-a[i].first);
		if (t>-1 && t!=a[i].second) {
			i=a[i].second;
			if (i>t) swap(i, t);
			break;
		} else { i++; t=-1; }
	}

	if (t==-1) {
		cout << "IMPOSSIBLE\n";
	} else cout << i+1 << ' ' << t+1 << '\n';
	
	return 0;
}