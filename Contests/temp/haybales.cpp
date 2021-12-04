#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("haybales.in","r",stdin);
    freopen("haybales.out","w",stdout);
    int n, q; cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(),v.end());
    set<array<int,2>> s;
    for (int i = 0; i < n; i++)
        s.insert({v[i],i});
    for (int i = 0; i < q; i++) {
        int x, y; cin >> x >> y;
        auto it = s.lower_bound({x,0});
        auto it2 = s.lower_bound({y,0});
        if (it2 == s.end() || it == s.end()) {
            if (it == s.end()) {
                cout << 0 << "\n";
            } else {
                array<int,2> a = *it;
                if (a[1] == x)
                    cout << n-a[1]+1 << "\n";
                else
                    cout << n-a[1] << "\n";
            }
        } else {
            array<int,2> a = *it;
            array<int,2> b = *it2;
            int e = 0;
            if (a[0] == x) e++;
            if (b[0] == y) e++;
            e = max(0,e-1);
            cout << b[1]-a[1]+e << "\n";
        }
    }
}
