#include<bits/stdc++.h>
using namespace std;
#define N 1000000

int main() {
	cin.tie(0)->sync_with_stdio(false);

	vector<int> p;
	vector<bool> s(N+1, true); s[0]=s[1]=false;
	for (int i = 2; i < 1000; ++i) {
		if (s[i]) {
			for (int j = i*i; j <= N; j+=i) s[j]=false;
			p.push_back(i);
		}
	}

	int n, x;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		int r=1;
		for (int j = 0; j < p.size() && x>1; ++j) {
			int t=1;
			while (x%p[j]==0) {
				x/=p[j]; t++;
			} r*=t;
		}
		cout << r*(x>1?2:1) << '\n';
	}

	return 0;
}