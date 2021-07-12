#include <bits/stdc++.h>
using namespace std;
#define int64 int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("lostcow.in","r",stdin);
    freopen("lostcow.out","w",stdout);
    int x, y; cin >> x >> y;
    int mov = 1, i = 0, ans = 0;
    while (true) {
        if (i%2 == 0) {
            if (x+mov >= y && y > x) {
                ans += y-x; break;
            } else {
                ans += mov*2;
            }
        } else {
            if (x-mov <= y && y < x) {
                ans += x-y; break;
            } else {
                ans += mov*2;
            }
        }
        i++; mov *= 2;
    }
    cout << ans << "\n";
}
