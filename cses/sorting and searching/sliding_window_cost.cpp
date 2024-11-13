#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, k, m, x=0, y=0;
multiset<int, greater<int>> l;
multiset<int> r;

void balance(int a, int b) {
	if (b<=m) { r.insert(a); l.erase(l.lower_bound(b)); y+=a; x-=b; }
	else { l.insert(a); r.erase(r.lower_bound(b)); x+=a; y-=b; }
	while (l.size()<(k+1)/2) { auto t=r.begin(); x+=*t; y-=*t; l.insert(*t); r.erase(t); }
	while (l.size()>(k+1)/2) { auto t=l.begin(); x-=*t; y+=*t; r.insert(*t); l.erase(t); }
	m=k%2?*l.begin():*l.begin()+*r.begin()>>1;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> k;
	vector<int> a(n), b(k);
	for (int i = 0; i < k; ++i) {
		cin >> a[i]; b[i]=a[i];
	} sort(b.begin(), b.end());
	m=k%2?b[(k-1)/2]:b[(k-1)/2]+b[(k+1)/2]>>1;
	for (int i = 0; i <= (k-1)/2; ++i) { l.insert(b[i]); x+=b[i]; }
	for (int i = (k+1)/2; i < k; ++i) { r.insert(b[i]); y+=b[i]; }
	cout << y-x+m*(k%2) << " \n"[k==n];

	for (int i = k, j = 0; i < n; ++i, j++) {
		cin >> a[i];
		balance(a[i], a[j]);
		cout << y-x+m*(k%2) << " \n"[i==n-1];
	}

	return 0;
}