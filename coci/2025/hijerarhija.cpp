#include<bits/stdc++.h>
using namespace std;

vector<int> in, out;
set<pair<int, int>> e;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, f=0;
	cin >> n;
	in.assign(n+1, 0);
	out.assign(n+1, 0);
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		e.insert({a,b});
		out[a]++; in[b]++;
		if (in[b]==2) f++;
	}

	int q;
	cin >> q;
	cout << (f==0?"DA":"NE") << '\n';
	for (int i = 0; i < q; ++i) {
		int a, b;
		cin >> a >> b;
		if (!e.count({a, b})) swap(a, b);
		e.erase({a, b});
		e.insert({b, a});
		in[b]--; out[b]++;
		in[a]++; out[a]--;
		if (in[a]==2) f++;
		if (in[b]==1) f--;
		cout << (f==0?"DA":"NE") << '\n';
	}
	
	return 0;
}