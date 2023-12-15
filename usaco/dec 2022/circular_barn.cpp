#include<bits/stdc++.h>
using namespace std;
#define N 5000005

bool c[N] = {false, true};
int dp[N] = {0,1};

int main() {
	cin.tie(0)->sync_with_stdio(false);
	
	vector<int> p = {2, 1, 2, 3};
	for (int i = 2; i < N; ++i) {
		if (!c[i]) {
			for (int j = i; j < N; j+=i) {
				c[j]=true;
			} p[i%4]=i;
		} dp[i]=(i-p[i%4])/2+1;
	}

	int t;
	cin >> t;
	while (t--) {
		int n, a, m=1e9;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> a;
			if (dp[a]/2 < m/2) m=dp[a];
		}

		if (m%2) cout << "Farmer John\n";
		else cout << "Farmer Nhoj\n";
	}

	return 0;
}