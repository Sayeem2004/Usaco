#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    vector<int> D(n+1);
    for (int i = 0; i < k; i++) {
        int a, b; cin >> a >> b;
        D[a-1]++;
        D[b]--;
    }
    vector<int> H(n);
    H[0] = D[0];
    for (int i = 1; i < n; i++) {
        H[i] = H[i-1]+D[i];
    }
    sort(H.begin(),H.end());
    cout << H[n/2] << "\n";
}
