#include<bits/stdc++.h>
using namespace std;

vector<int> pre, rin;
void construct(int i, int j, int s=0) {
	if (i>j) return;
	int c=pre[i+s];
	if (i<j) {
		construct(i, rin[c]-1, s+1);
		construct(rin[c]+1, j, s);
	} cout << c << ' ';
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	pre.reserve(n); rin.reserve(n+1);
	for (int i = 0; i < n; ++i) { cin >> pre[i]; }
	for (int i = 0; i < n; ++i) { int t; cin >> t; rin[t]=i; }
	construct(0, n-1);

	return 0;
}