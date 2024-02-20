#include<bits/stdc++.h>
using namespace std;
#define int long long

void divs(int n, set<int>& divs) {
	int i=1;
	for (; i*i < n; ++i) {
		if (n%i==0) {
			divs.insert(i);
			divs.insert(n/i);
		}
	} if (i*i==n) divs.insert(i);
}

bool check(vector<int> v, int m) {
	vector<int> u={v[0]%m, -1, -1};
	for (auto i : v) {
		int t=i%m;
		if (t==u[0] || t==u[1] || t==u[2]) continue;
		if (u[1]==-1) u[1]=t;
		else if (u[2]==-1) u[2]=t;
		else return false;
	} return true;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	set<int> s;
	vector<int> v;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		s.insert(x);
	} for (auto t = s.begin(); t != s.end(); ++t) v.push_back(*t);

	int t=v[0]/4;
	if (v.size() <= 3) {
		cout << t*(t+1)/2;
	} else {
		set<int> d;
		vector<int> p={v[3]-v[0], v[2]-v[0], v[1]-v[0], v[3]-v[1], v[2]-v[1], v[3]-v[2]};
		for (auto i : p) {
			divs(i, d);
		}

		int ans=0;
		for (auto i : d) {
			if (i<=t) {
				if (check(v, i)) ans+=i;
			} else break;
		} cout << ans << '\n';
	}

	return 0;
}