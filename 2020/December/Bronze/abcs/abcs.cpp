#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector<ll> v(7);
    for (int i = 0; i < 7; i++)
        cin >> v[i];
    sort(v.begin(),v.end());
    for (int i = 0; i < 7; i++) {
        for (int q = 0; q < 7; q++) {
            for (int r = 0; r < 7; r++) {
                if (i != q && q != r && i != r) {
                    if (v[i]+v[q]+v[r] == v[6]) {
                        cout << v[i] << " " << v[q] << " " << v[r] << "\n";
                        return 0;
                    }
                }
            }
        }
    }
}
