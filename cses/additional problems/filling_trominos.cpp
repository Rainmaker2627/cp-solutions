#include<bits/stdc++.h>
using namespace std;

vector<string> construct(int m, int n) {
    vector<string> ans;
    if (m%3!=0) return {};
    if (n%2==0) {
        ans.assign(m, "");
        while (n) {
            for (int i = 0; i < m; i+=3) {
                ans[i]+=(n%4?"AA":"CC");
                ans[i+1]+=(n%4?"AB":"CD");
                ans[i+2]+=(n%4?"BB":"DD");
            } n-=2;
        } return ans;
    } else {
        if (m==3) return {};
        else if (m%2==0) {
            if (n==1) return {};
            ans.assign(m, "");
            while (n%3!=0) {
                for (int i = 0; i < m; i+=3) {
                    ans[i]+=(n%3==1?"AA":"CC");
                    ans[i+1]+=(n%3==1?"AB":"CD");
                    ans[i+2]+=(n%3==1?"BB":"DD");
                } n-=2;
            }
            while (m) {
                for (int i = 0; i < n/3; i++) {
                    ans[m-2]+=(m%4?"EEF":"GGH");
                    ans[m-1]+=(m%4?"EFF":"GHH");
                } m-=2;
            } return ans;
        } else {
            if (n>3) {
                ans={"IIKKI", "IJKII", "JJIKK", "KIIJK", "KKJJI",  "IIKII",  "IKKJJ",  "JJIKJ",  "JIIKK"};
                for (int j = 0; j < n-5; j+=2) {
                    for (int i = 0; i < 9; i+=3) {
                        ans[i]+=(j%4?"AA":"CC");
                        ans[i+1]+=(j%4?"AB":"CD");
                        ans[i+2]+=(j%4?"BB":"DD");
                    }
                }
                auto temp=construct(m-9, n);
                for (auto i : temp) {
                    ans.push_back(i);
                }
                return ans;
            } else return {};
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        auto ans=construct(m, n);
        if (ans.empty()) {
            ans=construct(n, m);
            if (ans.empty()) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {
                        cout << ans[j][i];
                    } cout << '\n';
                }
            }
        } else {
            cout << "YES\n";
            for (auto i : ans) {
                cout << i << '\n';
            }
        }
    }

    return 0;
}