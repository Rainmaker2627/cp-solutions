#include<bits/stdc++.h>
using namespace std;
#define int long long

int inv(vector<int>& v, int a=0, int b=-1) {
	if (b==-1) b=v.size()-1;
	if (a!=b) {
		int m=(a+b)/2, t=inv(v, a, m)+inv(v, m+1, b);
		vector<int> s;
		int i=a, j=m+1;
		while (i<=m && j<=b)
			if (v[i]<v[j]) s.push_back(v[i++]);
			else { t+=m-i+1; s.push_back(v[j++]); }
		while (i<=m) s.push_back(v[i++]);
		while (j<=b) s.push_back(v[j++]);
		for (int i = a; i <= b; ++i) v[i]=s[i-a];
		return t;
	} return 0;
}

int floop(vector<int>& v) {
	int m=0;
	vector<bool> s(v.size(), false);
	for (int i = 0, j = 0; i < v.size(); ++i, j=i) {
		if (s[i]) continue;
		while (!s[j]) {
			s[j]=true;
			j=v[j]-1;
		} m++;
	} return m;
}

int lis(vector<int>& v) {
	vector<int> dp{0};
	for (int i = 0; i < v.size(); ++i) {
		int q=lower_bound(dp.begin(), dp.end(), v[i])-dp.begin();
		if (q==dp.size()) dp.push_back(v[i]);
		dp[q]=v[i];
	} return dp.size()-1;
}

int bseq(vector<int>& v) {
	int n=v.size(), m=v.size();
	for (int i = n-1; i >= 0; --i) {
		if (v[i]==m) m--;
	} return m;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v(n), s(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i]; s[i]=v[i];
	}

	cout << inv(s) << ' ' << n-floop(v) << ' ' << n-lis(v) << ' ' << bseq(v) << '\n';
	return 0;
}