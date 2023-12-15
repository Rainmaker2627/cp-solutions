#include<bits/stdc++.h>
using namespace std;
#define N 5000001

vector<int> p;
int s[N];

int main() {
	cin.tie(0)->sync_with_stdio(false);

	vector<bool> e(N, true);
	e[0]=e[1]=false;
	for (int i = 2; i < N; ++i) {
		if (!e[i]) continue;
		p.push_back(i);
		for (int j = i*i; j < N; j+=i) e[j]=false;
	}

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
	}
	
	return 0;
}