#include<bits/stdc++.h>
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	vector<int> x(n);
	for (int i = 0; i < n; ++i) {
		int s;
		cin >> s;
		x[s-1]=i;
	}

	int c=1;
	for (int i = 0; i < n; ++i) c+=(x[i-1]>x[i]);

	cout << c << '\n';
	return 0;
}