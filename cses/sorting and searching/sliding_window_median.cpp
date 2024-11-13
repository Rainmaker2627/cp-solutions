#include<bits/stdc++.h>
using namespace std;

int n, k;
multiset<int, greater<int>> l;
multiset<int> r;

void balance(int a, int b) {
	int m=*l.begin();
	if (b<=m) { l.erase(l.lower_bound(b)); r.insert(a); }
	else { r.erase(r.lower_bound(b)); l.insert(a); }
	while (l.size()<(k+1)/2) { l.insert(*r.begin()); r.erase(r.begin()); }
	while (l.size()>(k+1)/2) { r.insert(*l.begin()); l.erase(l.begin()); }
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> k;
	vector<int> a(n), b(k);
	for (int i = 0; i < k; ++i) {
		cin >> a[i]; b[i]=a[i];
	} sort(b.begin(), b.end());
	for (int i = 0; i <= (k-1)/2; ++i) l.insert(b[i]);
	for (int i = (k+1)/2; i < k; ++i) r.insert(b[i]);
	cout << *l.begin() << " \n"[k==n];

	for (int i = k, j = 0; i < n; ++i, j++) {
		cin >> a[i];
		balance(a[i], a[j]);
		cout << *l.begin() << " \n"[i==n-1];
	}

	return 0;
}