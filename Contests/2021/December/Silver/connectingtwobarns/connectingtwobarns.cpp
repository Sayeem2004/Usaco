#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

ll dist(array<ll, 2> a, array<ll, 2> b) {
    ll d1 = abs(a[0]-b[0]);
    ll d2 = abs(a[0]-b[1]);
    ll d3 = abs(a[1]-b[0]);
    ll d4 = abs(a[1]-b[1]);
    return min(d1, min(d2, min(d3, d4)));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll t; cin >> t; while (t--) {
        ll n, m; cin >> n >> m;
        vector<vector<ll>> A(n);
        for (ll i = 0; i < m; i++) {
            ll a, b; cin >> a >> b;
            a--; b--;
            A[a].push_back(b);
            A[b].push_back(a);
        }
        vector<bool> V(n, 0);
        vector<array<ll, 2>> C;
        for (ll i = 0; i < n; i++) {
            if (!V[i]) {
                ll mn = 100000, mx = 0;
                queue<ll> Q;
                Q.push(i);
                V[i] = 1;
                mn = min(mn, i);
                mx = max(mx, i);
                while (!Q.empty()) {
                    ll v = Q.front();
                    Q.pop();
                    for (ll u : A[v]) {
                        if (!V[u]) {
                            V[u] = 1;
                            mn = min(mn, u);
                            mx = max(mx, u);
                            Q.push(u);
                        }
                    }
                }
                C.push_back({mn, mx});
            }
        }
        array<ll, 2> sc, ec;
        for (ll i = 0; i < C.size(); i++) {
            if (C[i][0] == 0) sc = C[i];
            if (C[i][1] == n-1) ec = C[i];
        }
        ll ans = 1000000000000000;
        for (ll i = 0; i < C.size(); i++) {
            ll dist1 = dist(sc, C[i]);
            ll dist2 = dist(ec, C[i]);
            ans = min(ans, dist1*dist1 + dist2*dist2);
        }
        cout << ans << "\n";
    }
}
