#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<ll> V;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        V.push_back(x);
    }
    ll sum = V[0], best = V[0];
    for (int i = 1; i < n; i++) {
        sum = max(V[i],sum+V[i]);
        best = max(best, sum);
    }
    cout << best << "\n";
}
