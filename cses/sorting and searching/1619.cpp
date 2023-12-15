#include<bits/stdc++.h>
using namespace std;

int n;

bool acomp(int a, int b) { 
	return abs(a) < abs(b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	vector<int> t;
	for (int i = 0; i < n; ++i) {
		int s, l;
		cin >> s >> l;
		t.push_back(s);
		t.push_back(-l);
	} sort(t.begin(), t.end(), acomp);

	int c=0, m=0;
	for (auto i : t) {
		if (i>0) c++;
		else c--;
		m=max(c, m);
	}

	cout << m << '\n';
	return 0;
}