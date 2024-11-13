#include<bits/stdc++.h>
using namespace std;

const int inf=1e9;
map<char, int> nuc;

struct node {
	bool end;
	node *child[4];

	node() {
		end=false;
		for (int i = 0; i < 4; ++i) child[i]=nullptr;
	}

	void add(string s, int i=0) {
		if (i==s.length()) {
			end=true;
		} else {
			if (child[nuc[s[i]]]==nullptr) child[nuc[s[i]]]=new node();
			child[nuc[s[i]]]->add(s, i+1);
		}
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(false);

	nuc['A']=0; nuc['T']=1; nuc['G']=2; nuc['C']=3;

	int n, m;
	string t;
	cin >> n >> m >> t;

	node start;
	for (int i = 0; i < m; ++i) {
		int l;
		string s;
		cin >> l >> s;
		start.add(s);
	}

	vector<int> dp(n+1, inf); dp[0]=0;
	for (int i = 0; i < n; ++i) {
		node *cur=&start;
		for (int j = i; j < n; ++j) {
			cur=cur->child[nuc[t[j]]];
			if (cur==nullptr) break;
			if (cur->end) dp[j+1]=min(dp[j+1], dp[i]+1);
		}
	}

	cout << (dp[n]==inf?-1:dp[n]) << '\n';
	return 0;
}