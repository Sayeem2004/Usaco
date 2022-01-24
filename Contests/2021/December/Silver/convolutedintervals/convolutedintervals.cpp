#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n, m; cin >> n >> m;
    vector<array<ll, 2>> V(n);
    for (ll i = 0; i < n; i++) {
        ll a, b; cin >> a >> b;
        V[i] = {a, b};
    }
    map<array<ll, 2>, ll> MP;
    for (int i = 0; i < n; i++) {
        for (int q = 0; q < n; q++) {
            MP[{V[i][0]+V[q][0], V[i][1]+V[q][1]}]++;
        }
    }
    for (int i = 0; i <= 2*m; i++) {
        ll cnt = 0;
        for (auto x : MP) {
            array<ll, 2> val = x.first;
            if (val[0] <= i && val[1] >= i) cnt += x.second;
        }
        cout << cnt << "\n";
    }
}
