#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    vector<vector<ll>> V(n,vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int q = 0; q < n; q++) {
            cin >> V[i][q];
        }
    }
    vector<vector<ll>> P(n,vector<ll>(n));
    for (int i = 1; i <= n; i++) {
        for (int q = 1; q <= n; q++) {
            P[i-1][q-1] = i*q*(i+1)*(q+1)/4;
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll minL = 1000000000;
        for (int q = 1; q < n; q++) {
            minL = min(minL,V[i][q]);
            if (minL == 100) {
                ans += P[n-i-1][n-q-1]/4;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        ll minR = 1000000000;
        for (int q = n-1; q >= 0; q--) {
            minR = min(minR,V[i][q]);
            if (minR == 100) {
                ans += P[i][q]/4;
            }
        }
    }
    for (int q = 0; q < n; q++) {
        ll minD = 1000000000;
        for (int i = 0; i < n; i++) {
            minD = min(minD,V[i][q]);
            if (minD == 100) {
                ans += P[n-i-1][n-q-1]/4;
            }
        }
    }
    for (int q = 0; q < n; q++) {
        ll minU = 1000000000;
        for (int i = n-1; i >= 0; i--) {
            minU = min(minU,V[i][q]);
            if (minU == 100) {
                ans += P[i][q]/4;
            }
        }
    }
    cout << ans << "\n";
}
