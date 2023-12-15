#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct trans {
	ll a, b, w;

	void set(ll x, ll y, ll z) {
		a=x+1; b=y+1; w=z;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(false);

	ll n, s=0;
	cin >> n;
	vector<ll> h(n), c(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
		s+=h[i];
	} s/=n;

	vector<vector<int>> e(n, vector<int>());
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		e[--a].push_back(--b);
		e[b].push_back(a);
		c[a]++; c[b]++;
	}

	queue<int> bfs;
	for (int i = 0; i < n; ++i) {
		if (c[i]==1) bfs.push(i);
	}

	stack<trans> pull; queue<trans> push;
	while (!bfs.empty()) {
		int v=bfs.front();
		bfs.pop(); c[v]--;
		for (auto i : e[v]) {
			if (c[i]<1) continue;
			if (--c[i]==1) bfs.push(i);

			trans m;
			if (h[v]<s) {
				m.set(i, v, s-h[v]);
				h[i]-=s-h[v]; h[v]=s;
				pull.push(m);
			} else if (h[v]>s) {
				m.set(v, i, h[v]-s);
				h[i]+=h[v]-s; h[v]=s;
				push.push(m);
			}
		}
	}

	cout << pull.size()+push.size() << '\n';
	while (!push.empty()) {
		trans m = push.front();
		cout << m.a << ' ' << m.b << ' ' << m.w << '\n';
		push.pop();
	} while (!pull.empty()) {
		trans m = pull.top();
		cout << m.a << ' ' << m.b << ' ' << m.w << '\n';
		pull.pop();
	}

	return 0;
}