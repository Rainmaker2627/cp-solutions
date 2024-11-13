#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;

struct trie {
	bool end;
	trie *child[26];

	trie() {
		end=false;
		for (int i = 0; i < 26; ++i) child[i]=nullptr;
	}

	void build(string& s, int i=0) {
		if (i==s.length()) end=true;
		else {
			if (child[s[i]-'a']==nullptr) child[s[i]-'a']=new trie();
			child[s[i]-'a']->build(s, i+1);
		}
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, k;
	string s;
	cin >> s >> k;

	trie begin;
	for (int i = 0; i < k; ++i) {
		string t;
		cin >> t;
		begin.build(t);
	}

	n=s.length();
	vector<int> dp(n+1, 0); dp[0]=1;
	for (int i = 0; i < n; ++i) {
		trie *cur=&begin;
		for (int j = i; j < n; ++j) {
			cur=cur->child[s[j]-'a'];
			if (cur==nullptr) break;
			if (cur->end) dp[j+1]=(dp[j+1]+dp[i])%mod;
		}
	}

	cout << dp[n] << '\n';
	return 0;
}