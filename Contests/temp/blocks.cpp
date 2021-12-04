#include <bits/stdc++.h>
using namespace std;
#define int64 int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("blocks.in","r",stdin);
    freopen("blocks.out","w",stdout);
    int n; cin >> n;
    vector<int> alp(26,0);
    for (int i = 0; i < n; i++) {
        string x, y; cin >> x >> y;
        set<char> s;
        for (auto z : x) s.insert(z);
        for (auto z : y) s.insert(z);
        for (auto x : s) alp[x-'a']++;
    }
    for (auto x : alp)
        cout << x << "\n";
}
