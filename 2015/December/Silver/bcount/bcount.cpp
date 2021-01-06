#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("bcount.in","r",stdin);
    freopen("bcount.out","w",stdout);
    int n, m; cin >> n >> m;
    vector<int> v(n),v2(n),v3(n);
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x == 1) a++;
        if (x == 2) b++;
        if (x == 3) c++;
        v[i] = a;
        v2[i] = b;
        v3[i] = c;
    }
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        if (x != 1) {
            cout << v[y-1] - v[x-2] << " ";
            cout << v2[y-1] - v2[x-2] << " ";
            cout << v3[y-1] - v3[x-2] << "\n";
        } else {
            cout << v[y-1] << " ";
            cout << v2[y-1] << " ";
            cout << v3[y-1] << "\n";
        }
    }
}
