#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> V(n), P(n), S(n);
    for (int i = 0; i < n; i++) {
        cin >> V[i];
    }
    P[0] = V[0];
    for (int i = 1; i < n; i++)
        P[i] = __gcd(P[i-1], V[i]);
    S[n-1] = V[n-1];
    for (int i = n-2; i >= 0; i--)
        S[i] = __gcd(S[i+1], V[i]);
    int ans = max(S[1], P[n-2]);
    for (int i = 1; i < n-1; i++) {
        ans = max(ans, __gcd(P[i-1], S[i+1]));
    }
    cout << ans << "\n";
}
