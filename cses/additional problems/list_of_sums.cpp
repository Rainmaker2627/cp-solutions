#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, t;
vector<int> v, p;

bool solve(int a) {
	map<int, int> s;
	v.push_back(a);
	for (int i = 0; i < t; ++i) {
		if (v.size()>n) return false;
		if (s[p[i]]>0) s[p[i]]--;
		else {
			v.push_back(p[i]-v[0]);
			for (int j = 1; j < v.size()-1; ++j) {
				s[p[i]-v[0]+v[j]]++;
			}
		}
	} return true;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n;
	t=n*(n-1)/2;
	p.assign(t, 0);
	for (int i = 0; i < t; ++i) {
		cin >> p[i];
	} sort(p.begin(), p.end());

	for (int i = 2; i < n+2; ++i) {
		int a=p[0]+p[1]-p[i];
		if (a%2) continue;
		v.clear();
		if (solve(a/2)) break;
	}

	for (int i = 0; i < n; ++i) {
		cout << v[i] << ' ';
	}

	return 0;
}