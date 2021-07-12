#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define arr array

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("pairup.in","r",stdin);
    freopen("pairup.out","w",stdout);
    int n; cin >> n;
    vector<arr<int,2>> V(n);
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        V[i] = {b, a};
    }
    sort(V.begin(), V.end());
    int a = 0, b = n-1, mx = 0;
    while (a < b) {
        if (V[a][1] == V[b][1]) {
            mx = max(mx, V[a][0]+V[b][0]);
            V[a][1] = 0;
            V[b][1] = 0;
            a++; b--; continue;
        }
        if (V[a][1] > V[b][1]) {
            mx = max(mx, V[a][0]+V[b][0]);
            V[a][1] -= V[b][1];
            V[b][1] = 0;
            b--; continue;
        }
        if (V[a][1] < V[b][1]) {
            mx = max(mx, V[a][0]+V[b][0]);
            V[b][1] -= V[a][1];
            V[a][1] = 0;
            a++; continue;
        }
    }
    if (V[a][1] != 0) mx = max(mx, V[a][0]+V[a][0]);
    if (V[b][1] != 0) mx = max(mx, V[b][0]+V[b][0]);
    cout << mx << "\n";
}
