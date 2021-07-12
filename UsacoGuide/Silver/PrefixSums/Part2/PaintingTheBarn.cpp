#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("paintbarn.in","r",stdin);
    freopen("paintbarn.out","w",stdout);
    int n, k; cin >> n >> k;
    vector<vector<int>> P(1003, vector<int>(1003));
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        P[++x1][++y1]++;
        P[++x2][++y2]++;
        P[x1][y2]--;
        P[x2][y1]--;
    }
    for (int i = 1; i <= 1001; i++) {
        for (int q = 1; q <= 1001; q++) {
            P[i][q] = P[i][q] + P[i-1][q] + P[i][q-1] - P[i-1][q-1];
        }
    }
    int ans = 0;
    for (int i = 0; i < 1003; i++) {
        for (int q = 0; q < 1003; q++) {
            if (P[i][q] == k) ans++;
        }
    }
    cout << ans << "\n";
}
