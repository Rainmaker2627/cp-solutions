#include<bits/stdc++.h>
using namespace std;
#define int long long

const int inf=1e18+7;

struct node {
	int s;
	char c;
	node *l, *r;

	void print(int b, int e) {
		b=max(b, 1ll); e=min(e, s);
		if (b>e) return;
		if (c!='#') cout << c;
		else {
			l->print(b, e);
			r->print(b-l->s, e-l->s);
		}
	}
};

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int l, r, n;
	cin >> l >> r >> n;
	vector<pair<char, string>> q;
	for (int i = 0; i < n; ++i) {
		char c;
		string s;
		cin >> c >> s;
		q.push_back({c, s});
	} reverse(q.begin(), q.end());

	vector<node*> alph(26);
	for (char i = 'a'; i <= 'z'; ++i) alph[i-'a']=new node{1, i};
	for (int i = 0; i < n; ++i) {
		auto [c, s]=q[i];
		node* r=nullptr;
		for (char x : s) {
			node* t=alph[x-'a'];
			if (r==nullptr) r=t;
			else r=new node{min(inf, r->s+t->s), '#', r, t};
		} alph[c-'a']=r;
	}

	alph[0]->print(l, r);
	cout << '\n';
	return 0;
}