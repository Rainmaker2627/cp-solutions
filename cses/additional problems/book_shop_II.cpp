#include<bits/stdc++.h>
using namespace std;

struct max_queue {
    queue<int> q;
    deque<int> dq;

    void pop() {
        if (q.front()==dq.front()) dq.pop_front();
        q.pop();
    }

    int max() {
        return dq.front();
    }

    void push(int x) {
        q.push(x);
        while (!dq.empty() && x>dq.back()) dq.pop_back();
        dq.push_back(x);
    }

    int size() {
        return q.size();
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, x;
    cin >> n >> x;
    vector<int> h(n), s(n), k(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) cin >> k[i];
    
    vector<int> dp(x+1, 0);
    for (int i = 0; i < n; i++) {
        for (int r = 0; r < h[i]; r++) {
            max_queue q;
            for (int m = 0; m*h[i]+r <= x; m++) {
                if (q.size()>k[i]) q.pop();
                q.push(dp[m*h[i]+r]-m*s[i]);
                dp[m*h[i]+r]=q.max()+m*s[i];
            }
        }
    }

    for (int i = 1; i <= x; i++) {
        dp[i]=max(dp[i-1], dp[i]);
    } cout << dp[x] << '\n';

    return 0;
}