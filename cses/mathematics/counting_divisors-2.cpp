#include<bits/stdc++.h>
using namespace std;
 
int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n=1e6;
	vector<int> p;
	vector<bool> s(n+1, true);
	s[0]=s[1]=false;
	for (int i = 2; i < 1000; ++i) {
		if (s[i]) {
			for (int j = i*i; j <= n; j+=i) s[j]=false;
			p.push_back(i);
		}
	}

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x;
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