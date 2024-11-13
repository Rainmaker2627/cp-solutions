#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	string s;
	cin >> s;
	s=s+s;
	
	int n=s.length()/2, k=0;
	vector<int> pi(2*n, 0);
	for (int i = 1; i < 2*n; ++i) {
		int j=pi[i-k-1];
		while (j>0 && s[i]!=s[j+k]) {
			if (s[i]<s[k+j]) k=i-j;
			j=pi[j-1];
		} if (j==0 && s[i]!=s[j+k]) {
			if (s[i]<s[k+j]) k=i;
			pi[i-k]=0;
		} else pi[i-k]=j+1;
	}

	for (int i = k; i < n+k; ++i) cout << s[i];
	cout << '\n';

	return 0;
}