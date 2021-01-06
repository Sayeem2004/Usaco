#include <bits/stdc++.h>
using namespace std;
#define int64 int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("shuffle.in","r",stdin);
    freopen("shuffle.out","w",stdout);
    int n; cin >> n;
    vector<int> change(n);
    for (int i = 0; i < n; i++)
        cin >> change[i];
    vector<int> v(n), v2(n), v3(n), v4(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n; i++)
        v2[i] = v[change[i]-1];
    for (int i = 0; i < n; i++)
        v3[i] = v2[change[i]-1];
    for (int i = 0; i < n; i++)
        v4[i] = v3[change[i]-1];
    for (auto x : v4)
        cout << x << "\n";
}
