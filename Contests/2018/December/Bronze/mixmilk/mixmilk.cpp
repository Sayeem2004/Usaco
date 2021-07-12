#include <bits/stdc++.h>
using namespace std;
#define int64 int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("mixmilk.in","r",stdin);
    freopen("mixmilk.out","w",stdout);
    vector<int> buc(3), siz(3);
    for (int i = 0; i < 3; i++) {
        cin >> siz[i]; cin >> buc[i];
    }
    for (int i = 1; i <= 100; i++) {
        int x = min(siz[i%3]-buc[i%3],buc[(i-1)%3]);
        buc[i%3] += x;
        buc[(i-1)%3] -= x;
    }
    for (auto x : buc)
        cout << x << "\n";
}
