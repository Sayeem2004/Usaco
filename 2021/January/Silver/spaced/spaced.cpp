#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<vector<int>> v(n,vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int q = 0; q < n; q++) {
            cin >> v[i][q];
        }
    }
    int ans = 0;
    int i = 1;
    while (i < n) {
        for (int q = 0; q < n; q++) {
            ans += max(v[i][q],v[i-1][q]);
        }
        i += 2;
    }
    if (n%2 == 1) {
        for (int i = 0; i < n; i++) {
            ans += v[n-1][i];
        }
    }
    cout << ans << "\n";
}
