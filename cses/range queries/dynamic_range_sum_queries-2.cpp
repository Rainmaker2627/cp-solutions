#include<bits/stdc++.h>
using namespace std;
#define int long long

struct bit {
	int n;
	vector<int> ft;

	bit(vector<int>& a) {
		n=a.size()+1;
		ft.assign(n, 0);
		for (int i = 1; i < n; ++i) {
			ft[i] += a[i-1];
			int r = i+(i&-i);
			if (r<n) ft[r] += ft[i];
		}
	}

	int sum(int a) {
		int s=0;
		for (; a; a-=a&-a) s += ft[a];
		return s;
	}

	void add(int a, int v) {
		for (; a<n; a+=a&-a) ft[a]+=v;
	}
};

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	bit ft(v);

	int t, a, b;
	for (int i = 0; i < q; ++i) {
		cin >> t >> a >> b;
		if (t==1) {
			ft.add(a, b-v[a-1]);
			v[a-1]=b;
		} else {
			cout << ft.sum(b)-ft.sum(a-1) << '\n';
		}
	}

	return 0;
}