#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define arr array

vector< arr<ll, 3> > subset(vector< arr<ll, 2> > a) {
    vector< arr<ll, 3> > s(1 << a.size());
    for (int b = 0; b < (1 << a.size()); b++) {
        ll x = 0, y = 0;
        for (int i = 0; i < a.size(); i++) {
            if (b&(1<<i)) {
                x += a[i][0];
                y += a[i][1];
            }
        }
        s[b] = {x, y, __builtin_popcount(b)};
    }
    return s;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    ll x, y; cin >> x >> y;
    vector< arr<ll, 2> > A1(n/2);
    vector< arr<ll, 2> > A2(n-n/2);
    for (int i = 0; i < n/2; i++) cin >> A1[i][0] >> A1[i][1];
    for (int i = 0; i < n-n/2; i++) cin >> A2[i][0] >> A2[i][1];
    vector< arr<ll, 3> > S1 = subset(A1);
    vector< arr<ll, 3> > S2 = subset(A2);
    sort(S1.begin(), S1.end());
    sort(S2.begin(), S2.end());
    vector< vector<int> > P(n+1, vector<int>(S2.size()+1, 0));
    for (int i = 0; i < S2.size(); i++) {
        P[S2[i][2]][i+1] += 1;
        for (int q = 0; q <= n; q++) {
            P[q][i+1] += P[q][i];
        }
    }
    vector<ll> ans(n+1);
    for (auto p : S1) {
        if (p[0]+(*S2.begin())[0] > x) break;
        arr<ll, 3> temp1 = {x-p[0], y-p[1], 0};
        arr<ll, 3> temp2 = {x-p[0], y-p[1], n};
        auto itr1 = lower_bound(S2.begin(), S2.end(), temp1);
        auto itr2 = upper_bound(S2.begin(), S2.end(), temp2);
        for (int k = 0; k <= n-p[2]; k++) {
            ans[k+p[2]] += (P[k][itr2-S2.begin()] - P[k][itr1-S2.begin()]);
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << "\n";
}
