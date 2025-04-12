#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int a, b, n;
    cin >> a >> b >> n;
    vector<int> prog(n), art(n);
    vector<pair<int, int>> ord;
    for (int i = 0; i < n; i++) {
        cin >> prog[i] >> art[i];
        ord.push_back({a==0?-art[i]:-prog[i], i});
    } sort(ord.begin(), ord.end());
    if (a==0) { swap(a, b); swap(prog, art); }

    int ans=0;
    set<pair<int, int>> swap, loart, loprog;
    for (int i = 0; i < a; i++) {
        auto [s, j]=ord[i];
        swap.insert({prog[j]-art[j], j});
        ans+=prog[j];
    } for (int i = a; i < n; i++) {
        auto [s, j]=ord[i];
        loart.insert({-art[j], j});
        loprog.insert({-prog[j], j});
    }
    
    for (int r = 0; r < b; r++) {
        auto [a, i] = *swap.begin(); a=-a;
        auto [b, j] = *loart.begin(); b=-b;
        auto [c, k] = *loprog.begin(); c=-c;
        if (a+c>b) {
            ans+=a+c;
            swap.erase({-a, i});
            loart.erase({-art[k], k});
            loprog.erase({-c, k});
            swap.insert({prog[k]-art[k], k});
        } else {
            ans+=b;
            loart.erase({-b, j});
            loprog.erase({-prog[j], j});
        }
    }

    cout << ans << '\n';

    return 0;
}