#include <bits/stdc++.h>
using namespace std;
#define int64 int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("billboard.in","r",stdin);
    freopen("billboard.out","w",stdout);
    vector<vector<int>> v(2001,vector<int>(2001,0));
    int x, y, x2, y2;
    cin >> x >> y >> x2 >> y2;
    for (int i = y; i <= y2; i++)
        for (int q = x; q <= x2; q++)
            v[i+1000][q+1000] = 1;
    cin >> x >> y >> x2 >> y2;
    for (int i = y; i <= y2; i++)
        for (int q = x; q <= x2; q++)
            v[i+1000][q+1000] = 1;
    cin >> x >> y >> x2 >> y2;
    for (int i = y; i <= y2; i++)
        for (int q = x; q <= x2; q++)
            v[i+1000][q+1000] = 2;
    int ans = 0;
    for (int i = 0; i < 2001; i++)
        for (int q = 0; q < 2001; q++)
            if (v[i][q] == 1) ans++;
    cout << ans << "\n";
}
