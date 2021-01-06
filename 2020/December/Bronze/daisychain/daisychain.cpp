#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int q = i; q < n; q++) {
            int avg = 0;
            for (int r = i; r <= q; r++)
                avg += v[r];
            if (avg%(q-i+1) != 0) {
                continue;
            } else {
                avg /= (q-i+1);
            }
            for (int r = i; r <= q; r++) {
                if (v[r] == avg) {
                    ans++; break;
                }
            }
        }
    }
    cout << ans << "\n";
}
