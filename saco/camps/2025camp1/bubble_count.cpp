#include<bits/stdc++.h>
using namespace std;

struct value {
	int v, i;
	bool operator<(value b) {
		if (v==b.v) return i<b.i;
		return v<b.v;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	vector<value> v(n);
	for (int i = 0; i < n; ++i) {
		v[i].i=i;
		cin >> v[i].v;
	} sort(v.begin(), v.end());

	int a=0;
	for (int i = 0; i < n; ++i) {
		a=max(a, v[i].i-i);
	} cout << a+1 << '\n';

	return 0;
}