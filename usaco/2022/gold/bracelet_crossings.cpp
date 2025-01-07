#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n, m, p=true;
        cin >> n >> m;
        vector<int> par(n+1, -1), life(n+1, -1), cord;
        for (int i = 0; i < m; i++) {
            int k;
            cin >> k;
            stack<int> s;
            vector<int> ord;
            s.push(0);
            for (int j = 0; j < k; j++) {
                int c;
                cin >> c;
                if (s.top()==c) s.pop();
                else {
                    if (par[c]==-1) par[c]=s.top();
                    else if (par[c]!=s.top()) p=false;
                    ord.push_back(c);
                    s.push(c);
                }
            } p&=(s.size()==1);
            int c=0;
            for (auto j : ord) {
                if (life[j]==-1) life[j]=i;
                else if (life[j]==i-1) {
                    while (c<cord.size() && cord[c]!=j) c++;
                    if (c==cord.size()) p=false;
                    life[j]=i;
                } else p=false;
            } swap(ord, cord);
        } cout << (p?"YES":"NO") << '\n';
    }

    return 0;
}