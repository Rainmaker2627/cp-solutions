#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> g(n);
	for (int i = 0; i < n; ++i) {
		cin >> g[i];
	}

	// assume n>1 as otherwise the game makes no sense
	int c=1;
	vector<int> a;
	for (int i = 1; i < n; ++i) {
		if (g[i]>g[i-1] && g[i-1]>g[i-2]) c++;
		else if (g[i]<g[i-1] && g[i-1]<g[i-2]) c--;			
		else {
			a.push_back(c);
		}
	}

	return 0;
}