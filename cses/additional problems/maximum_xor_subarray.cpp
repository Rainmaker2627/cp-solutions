#include<bits/stdc++.h>
using namespace std;

const int max_depth=30;
struct trie {
	int depth, rep;
	trie* bits[2];

	trie(int d) {
		depth=d;
		for (int i = 0; i < 2; ++i) bits[i]=nullptr;
	}

	void insert(int n) {
		if (depth==max_depth) { rep=n; return; }
		bool b=n&(1<<(max_depth-depth-1));
		if (bits[b]==nullptr) bits[b]=new trie(depth+1);
		bits[b]->insert(n);
	}

	int maxcomp(int c) {
		if (depth==max_depth) return rep;
		bool b=c&(1<<(max_depth-depth-1));
		if (bits[!b]==nullptr) b=!b;
		return bits[!b]->maxcomp(c);
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(false);

	trie t(0);
	t.insert(0);
	int n, x, m=0, s=0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		t.insert(s^=x);
		m=max(m, s^t.maxcomp(s));
	} cout << m << '\n';

	return 0;
}