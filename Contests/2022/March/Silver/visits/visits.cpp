#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define arr array

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    vector<arr<ll,3>> E(n);
    vector<ll> S(n);
    for (ll i = 0; i < n; i++) {
        ll v, w; cin >> v >> w;
        E[i] = {i, v-1, w};
        S[i] += w;
        S[v-1] -= w;
    }
    ll v, max = -1000000000;
    for (int i = 0; i < n; i++) {
        if (S[i] > max) {
            v = i;
            max = S[i];
        }
    }
    vector<ll> D(n, -1000000000);
    D[v] = 0;
    for (ll j = 0; j < n; j++) {
        bool br = false;
        for (ll i = 0; i < n; i++) {
            if (D[E[i][0]] > -1000000000) {
                if (D[E[i][1]] < D[E[i][0]] + E[i][2] && E[i][1] != v) {
                    D[E[i][1]] = D[E[i][0]] + E[i][2];
                    br = true;
                }
            }
        }
        if (!br) break;
    }
    ll ans = 0;
    for (ll x : D) {
        if (x > ans) ans = x;
    }
    cout << ans << "\n";
}
