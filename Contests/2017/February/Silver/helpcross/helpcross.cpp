#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("helpcross.in","r",stdin);
    freopen("helpcross.out","w",stdout);
    int n, m; cin >> n >> m;
    multiset<int> T;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        T.insert(a);
    }
    vector<pair<int,int>> P(m);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        P[i] = make_pair(b,a);
    }
    sort(P.begin(),P.end());
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int b = P[i].first;
        int a = P[i].second;
        auto itr = T.lower_bound(a);
        if (itr != T.end()) {
            int c = *itr;
            if (c <= b) {
                ans++;
                T.erase(itr);
            }
        }
    }
    cout << ans << "\n";
}
