#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod=1e9+7;
int exp(int a, int b, int m) {
    int x=1;
    while (b) {
        if (b%2) x=x*a%m;
        a=a*a%m; b/=2;
    } return x;
}

signed main() {
    ifstream cin("poetry.in");
    ofstream cout("poetry.out");

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> s(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> c[i];
    }
    
    vector<int> dp(k+1, 0); dp[0]=1;
    for (int j = 1; j <= k; j++) {
        for (int i = 0; i < n; i++) {
            if (j>=s[i]) dp[j]=(dp[j]+dp[j-s[i]])%mod;
        }
    }

    vector<int> rc(n+1, 0);
    for (int i = 0; i < n; i++) {
        rc[c[i]]=(rc[c[i]]+dp[k-s[i]])%mod;
    }

    map<char, int> oc;
    for (int i = 0; i < m; i++) {
        char c;
        cin >> c;
        oc[c]++;
    }
    
    int ans=1;
    for (char c = 'A'; c <= 'Z'; c++) {
        if (oc[c]==0) continue;
        int r=0;
        for (int i = 1; i <= n; i++) {
            if (rc[i]==0) continue;
            r=(r+exp(rc[i], oc[c], mod))%mod;
        } ans=ans*r%mod;
    } cout << ans << '\n';

    return 0;
}