#include<bits/stdc++.h>
using namespace std;

vector<char> sol;

struct trie_node {
	bool end;
	int depth;
	trie_node* child[26];

	trie_node(int d) {
		end=false;
		depth=d;
		for (int i = 0; i < 26; ++i) child[i]=nullptr;
	}

	void add(string s, int i=0) {
		if (i==s.length()) {
			end=true;
		} else {
			if (child[s[i]-'a']==nullptr) child[s[i]-'a']=new trie_node(depth+1);
			child[s[i]-'a']->add(s, i+1);
		}
	}

	void traverse(char avoid) {
		if (end) sol.push_back('P');
		for (char i = 'a'; i <= 'z'; ++i) {
			if (i==avoid || child[i-'a']==nullptr) continue;
			sol.push_back(i);
			child[i-'a']->traverse('-');
			sol.push_back('-');
		}
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;

	string l="";
	trie_node begin(0);
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		if (s.length()>l.length()) l=s;
		begin.add(s);
	}

	trie_node *cur = &begin;
	for (int i = 0; i < l.length(); ++i) {
		cur->traverse(l[i]);
		cur=cur->child[l[i]-'a'];
		sol.push_back(l[i]);
	} sol.push_back('P');

	cout << sol.size() << '\n';
	for (auto i : sol) {
		cout << i << '\n';
	}

	return 0;
}