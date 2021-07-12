#include <bits/stdc++.h>
using namespace std;
#define int64 int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("cbarn.in","r",stdin);
    freopen("cbarn.out","w",stdout);
    int n; cin >> n;
    vector<int> v(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        int curr = 0;
        for (int q = 0; q < n; q++) {
            if (q >= i) curr += (q-i) * v[q];
            else curr += (n-i+q) * v[q];
        }
        ans = min(ans,curr);
    }
    cout << ans << "\n";
}
