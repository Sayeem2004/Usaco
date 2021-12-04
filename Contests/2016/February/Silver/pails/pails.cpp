#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define arr array

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("pails.in","r",stdin);
    freopen("pails.out","w",stdout);
    int x, y, k, m; cin >> x >> y >> k >> m;
    vector<vector<bool>> V(x+1, vector<bool>(y+1, 0));
    priority_queue<arr<int,3>> PQ;
    PQ.push({0,0,0});
    while (!PQ.empty()) {
        arr<int,3> v = PQ.top(); PQ.pop();
        if (!V[v[1]][v[2]]) V[v[1]][v[2]] = 1;
        else continue;
        if (-v[0] < k) {
            if (!V[x][v[2]]) PQ.push({v[0]-1, x, v[2]});
            if (!V[v[1]][y]) PQ.push({v[0]-1, v[1], y});
            if (!V[0][v[2]]) PQ.push({v[0]-1, 0, v[2]});
            if (!V[v[1]][0]) PQ.push({v[0]-1, v[1], 0});
            int d1 = v[1]+v[2]-x, d2 = v[1]+v[2]-y;
            if (!V[min(x, x+d1)][max(0, d1)]) PQ.push({v[0]-1, min(x, x+d1), max(0, d1)});
            if (!V[max(0, d2)][min(y, y+d2)]) PQ.push({v[0]-1, max(0, d2), min(y, y+d2)});
        }
    }
    int ans = m;
    for (int i = 0; i < x+1; i++) {
        for (int q = 0; q < y+1; q++) {
            if (V[i][q]) ans = min(ans, abs(m-(i+q)));
        }
    }
    cout << ans << "\n";
}
