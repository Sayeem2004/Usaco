#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("div7.in","r",stdin);
    freopen("div7.out","w",stdout);
    int n; cin >> n;
    vector<int> P(n+1, 0);
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        P[i] = (P[i-1] + a) % 7;
    }
    map<int, int> M;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (M[P[i]] == 0) M[P[i]] = i;
        ans = max(ans, i - M[P[i]]);
    }
    cout << ans << "\n";
}
