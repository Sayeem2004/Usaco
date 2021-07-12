#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("maxcross.in","r",stdin);
    freopen("maxcross.out","w",stdout);
    int n, k, r; cin >> n >> k >> r;
    vector<int> P(n+1);
    for (int i = 0; i < r; i++) {
        int a; cin >> a;
        P[a] = 1;
    }
    for (int i = 1; i <= n; i++)
        P[i] += P[i-1];
    int ans = 1000000000;
    for (int i = k; i <= n; i++)
        ans = min(ans, P[i]-P[i-k]);
    cout << ans << "\n";
}
