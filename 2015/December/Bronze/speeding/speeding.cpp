#include <bits/stdc++.h>
using namespace std;
#define int64 int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("speeding.in","r",stdin);
    freopen("speeding.out","w",stdout);
    vector<int> spd(100,0), jrn(100,0);
    int n, m; cin >> n >> m;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        mx += x;
        for (int q = 0; q < mx; q++)
            if (spd[q] == 0)
                spd[q] = y;
    }
    mx = 0;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        mx += x;
        for (int q = 0; q < mx; q++)
            if (jrn[q] == 0)
                jrn[q] = y;
    }
    int ans = 0;
    for (int i = 0; i < 100; i++) {
        ans = max(jrn[i]-spd[i],ans);
    }
    cout << ans << "\n";
}
