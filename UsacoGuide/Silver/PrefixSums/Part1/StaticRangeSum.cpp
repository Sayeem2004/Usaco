#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<ll> P(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> P[i];
        P[i] += P[i-1];
    }
    for (int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        cout << P[r] - P[l] << "\n";
    }
}
