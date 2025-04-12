#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, j;
struct trie {
    int l, v;
    map<int, trie*> next;

    int go(vector<int>& r, int p, int l=0) {
        if (l==j) return v++;
        if (!next[r[l]-p]) next[r[l]-p]=new trie{l+1, 0};
        return next[r[l]-p]->go(r, p, l+1);
    }
};

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    string s;
    cin >> s;

    set<char> c;
    n=s.length(), j=0;
    map<char, int> m;
    for (int i = 0; i < n; i++) c.insert(s[i]);
    for (auto i : c) m[i]=j++;

    int p=0, ans=0;
    vector<int> r(j, 0);
    trie* t=new trie{0, 0}; t->go(r, 0);
    for (int i = 0; i < n; i++) {
        if (r[m[s[i]]]++==p) {
            p=n+1;
            for (auto j : r) p=min(p, j);
        } ans+=t->go(r, p);
    } cout << ans << '\n';

    return 0;
}