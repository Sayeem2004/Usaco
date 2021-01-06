#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("highcard.in","r",stdin);
    freopen("highcard.out","w",stdout);
    int n; cin >> n;
    vector<int> v(n);
    set<int> s;
    for (int i = 1; i <= 2*n; i++)
        s.insert(i);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        s.erase(v[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x = v[i];
        if (s.lower_bound(x) != s.end()) {
            ans++;
            s.erase(s.lower_bound(x));
        } else {
            s.erase(s.lower_bound(0));
        }
    }
    cout << ans << "\n";
}
