#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

map<ll, ll> T;

array<ll, 2> get(vector<ll> P, ll s, ll e) {
    array<ll, 2> ret = {0, 0};
    if (s == -1 || e == -1) {
        ll sm = 0;
        for (ll i = 0; i < P.size(); i++) {
            sm += T[P[i]];
        }
        ret = {0, sm};
        return ret;
    } else {
        ll sm = 0, mxp = -1, mx = 0;
        for (ll i = 0; i < P.size(); i++) {
            sm += T[P[i]];
            if (T[P[i]] > mx) {
                mx = T[P[i]];
                mxp = P[i];
            }
        }
        ll pos1 = min(e-1, mxp + (mxp-s)), val1 = 0;
        for (int i = 0; i < P.size(); i++) {
            if (abs(P[i]-s) >= abs(P[i]-pos1) && abs(P[i]-e) > abs(P[i]-pos1))
                val1 += T[P[i]];
        }
        ll pos2 = max(s+1, mxp - (e-mxp)), val2 = 0;
        for (int i = 0; i < P.size(); i++) {
            if (abs(P[i]-s) > abs(P[i]-pos2) && abs(P[i]-e) >= abs(P[i]-pos2))
                val2 += T[P[i]];
        }
        ret = {max(val1, val2), sm - max(val1, val2)};
        return ret;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll k, m, n; cin >> k >> m >> n;
    vector<array<ll, 2>> P(k+m);
    for (ll i = 0; i < k; i++) {
        ll a, b; cin >> a >> b;
        T[a] = b;
        P[i] = {a, 0};
    }
    for (ll i = 0; i < m; i++) {
        ll a; cin >> a;
        P[k+i] = {a, 1};
    }
    sort(P.begin(),P.end());
    vector<ll> V;
    ll prev = -1;
    for (ll i = 0; i < k+m; i++) {
        if (P[i][1] == 1) {
            vector<ll> TMP;
            for (ll q = prev+1; q < i; q++) {
                TMP.push_back(P[q][0]);
            }
            if (TMP.size() == 0) {
                prev = i;
            } else {
                array<ll, 2> val = get(TMP, (prev == -1 ? -1 : P[prev][0]), P[i][0]);
                V.push_back(val[0]);
                V.push_back(val[1]);
                prev = i;
            }
        }
    }
    vector<ll> TMP;
    for (ll q = prev+1; q < k+m; q++) {
        TMP.push_back(P[q][0]);
    }
    if (TMP.size() != 0) {
        array<ll, 2> val = get(TMP, P[prev][0], -1);
        V.push_back(val[0]);
        V.push_back(val[1]);
    }
    sort(V.rbegin(), V.rend());
    ll ans = 0;
    for (int i = 0; i < min((ll)V.size(), n); i++) {
        ans += V[i];
    }
    cout << ans << "\n";
}
