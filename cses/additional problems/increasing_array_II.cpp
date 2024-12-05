#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, a=0;
	cin >> n;
	priority_queue<int> pq;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		pq.push(x);
		if (pq.top()>x) {
			a+=pq.top()-x;
			pq.pop();
			pq.push(x);
		}
	} cout << a << '\n';

	return 0;
}