#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define arr array

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<arr<ll, 2>> V(n*2);
    for (int i = 0; i < n*2; i++) {
        int x; cin >> x;
        V[i] = {x, i % 2 == 0 ? 1 : -1};
    }
    sort(V.begin(), V.end());
    int ans = 0, curr = 0;
    for (int i = 0; i < n*2; i++) {
        curr += V[i][1];
        ans = max(ans,curr);
    }
    cout << ans << "\n";
}
