#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("hps.in","r",stdin);
    freopen("hps.out","w",stdout);
    int n; cin >> n;
    vector<vector<int>> P(n+1, vector<int>(3));
    for (int i = 1; i <= n; i++) {
        char c; cin >> c;
        P[i][0] = P[i-1][0] + (c == 'H');
        P[i][1] = P[i-1][1] + (c == 'P');
        P[i][2] = P[i-1][2] + (c == 'S');
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = max(ans, P[i][0]+P[n][1]-P[i][1]);
        ans = max(ans, P[i][0]+P[n][2]-P[i][2]);
    }
    for (int i = 0; i <= n; i++) {
        ans = max(ans, P[i][1]+P[n][0]-P[i][0]);
        ans = max(ans, P[i][1]+P[n][2]-P[i][2]);
    }
    for (int i = 0; i <= n; i++) {
        ans = max(ans, P[i][2]+P[n][0]-P[i][0]);
        ans = max(ans, P[i][2]+P[n][1]-P[i][1]);
    }
    cout << ans << "\n";
}
