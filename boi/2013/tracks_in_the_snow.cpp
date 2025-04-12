#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> moves={{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    vector<string> tr(h);
    for (int i = 0; i < h; i++) {
        cin >> tr[i];
    }

    int ans=0;
    char c=tr[0][0];
    queue<pair<int, int>> a, b;
    a.push({0, 0});
    while (!a.empty()) {
        auto [x, y]=a.front();
        a.pop();

        for (auto [dx, dy] : moves) {
            if (x+dx<0 || x+dx>=h || y+dy<0 || y+dy>=w) continue;
            
            if (tr[x+dx][y+dy]==c) a.push({x+dx, y+dy});
            else if (tr[x+dx][y+dy]!='.') b.push({x+dx, y+dy});
            if (tr[x+dx][y+dy]!='.') tr[x+dx][y+dy]='.';
        }

        if (a.empty()) {
            swap(a, b);
            ans++;
            c='F'+'R'-c;
        }
    } cout << ans << '\n';

    return 0;
}