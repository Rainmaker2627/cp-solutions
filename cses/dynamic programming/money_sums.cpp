#include<bits/stdc++.h>
using namespace std;

int n;
int x[100];
bool dp[100001];

int main() {
	cin.tie(0)->sync_with_stdio(false);
	
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
	}

	vector<int> p = {0};
	for (int i = 0; i < n; ++i) {
		int t=p.size();
		for (int j = 0; j < t; ++j) {
			if (!dp[x[i]+p[j]]) {
				p.push_back(x[i]+p[j]);
				dp[x[i]+p[j]]=true;
			}
		}
	} sort(p.begin(), p.end());

	cout << p.size()-1 << '\n';
	for (int i = 1; i < p.size()-1; ++i) {
		cout << p[i] << ' ';
	} cout << p[p.size()-1] << '\n';

	return 0;
}