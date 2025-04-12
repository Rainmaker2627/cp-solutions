#include<bits/stdc++.h>
using namespace std;

int n;
string s;
bool ok(string a, string b) {
    int j=0, v=0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i]!=b[j] && v==0) { v++; i--; }
        else if (a[i] != b[j]) return false;
        j++;
    } return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

	cin >> n >> s;
    if (n%2 == 0) { cout << "NOT POSSIBLE\n"; return 0; }

    set<string> ans;
    string a1 = s.substr(0, n/2), b1 = s.substr(n/2);
    string a2 = s.substr(n/2+1), b2 = s.substr(0, n/2+1);
    if (ok(a1, b1)) ans.insert(a1);
    if (ok(a2, b2)) ans.insert(a2);
    if (ans.size() == 0) cout << "NOT POSSIBLE\n";
    else if (ans.size() > 1) cout << "NOT UNIQUE\n";
    else cout << *ans.begin() << '\n';

    return 0;
}