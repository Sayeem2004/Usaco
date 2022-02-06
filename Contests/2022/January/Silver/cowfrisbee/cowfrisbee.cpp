#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    int n; cin >> n;
    vector<int> V(n);
    for (int &x : V) cin >> x;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int mx = 0;
        for (int q = i-1; q >= 0; q--) {
            if (V[q] > mx && V[i] > mx) ans += i-q+1;
            mx = max(mx, V[q]);
        }
    }
    cout << ans << "\n";
}
