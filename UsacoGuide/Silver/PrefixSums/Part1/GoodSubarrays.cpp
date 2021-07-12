#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--) {
        ll n; cin >> n;
        vector<ll> P(n+1);
        ll sm = 0;
        for (int i = 1; i <= n; i++) {
            char c; cin >> c;
            sm += (ll)c-48;
            P[i] = sm - i;
        }
        map<ll, ll> M;
        ll ans = 0;
        for (int i = 0; i <= n; i++) {
            ans += M[P[i]];
            M[P[i]]++;
        }
        cout << ans << "\n";
    }
}
