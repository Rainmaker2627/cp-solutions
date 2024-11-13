#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef pair<pair<int, int>, int> ppi;

int n;
bool fsort(ppi a, ppi b) { return (a.f.f==b.f.f?a.f.s>b.f.s:a.f.f<b.f.f); }

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n;
	vector<ppi> f;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		f.push_back({{a, b}, i});
	} sort(f.begin(), f.end(), fsort);

	int m=-1;
	vector<bool> a(n, false), b(n, false);
	for (int i = 0; i < n; ++i) {
		if (f[i].f.s>m) {
			m=f[i].f.s;
		} else b[f[i].s]=true;
	} m=1e9+1;
	for (int i = n-1; i >= 0; --i) {
		if (f[i].f.s<m) {
			m=f[i].f.s;
		} else a[f[i].s]=true;
	}

	for (int i = 0; i < n-1; ++i) {
		cout << a[i] << ' ';
	} cout << a[n-1] << '\n';
	for (int i = 0; i < n-1; ++i) {
		cout << b[i] << ' ';
	} cout << b[n-1] << '\n';

	return 0;
}