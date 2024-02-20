#include<bits/stdc++.h>
using namespace std;
#define M 1e6

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> a(M+1);
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		a[x]++;
	}

	for (int i = M; i > 0; --i) {
		int c=0;
		for (int j = i; j <= M; j += i) c+=a[j];
		if (c>1) { cout << i << '\n'; break; }
	}

	return 0;
}