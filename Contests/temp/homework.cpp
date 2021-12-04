#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("homework.in","r",stdin);
    freopen("homework.out","w",stdout);
    int n; cin >> n;
    multiset<int> s;
    vector<int> v(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        s.insert(v[i]);
        sum += v[i];
    }
    int maxk = 0;
    ll max = 0;
    for (int i = 0; i < n-2; i++) {
        int a = v[i];
        s.erase(s.find(a));
        sum -= a;
        ll sum2 = sum - *s.lower_bound(0);
        if (sum2 * (n-maxk) > max * (n-i-1)) {
            max = sum2;
            maxk = i+1;
        }
    }
    cout << maxk << "\n";
}
