#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("maxcross.in","r",stdin);
    freopen("maxcross.out","w",stdout);
    int n, k, r; cin >> n >> k >> r;
    vector<int> B(r);
    for (int i = 0; i < r; i++) cin >> B[i];
    sort(B.begin(),B.end());
    vector<int> D(r+1);
    D[0] = B[0]-0-1;
    for (int i = 1; i < r; i++) D[i] = B[i]-B[i-1]-1;
    D[r] = n-B[r-1];
    int ans = 100000;
    for (int i = 0; i < r+1; i++) {
        int q = i+1, sum = D[i];
        while (sum < k and q < r+1) {
            sum += D[q]+1;
            q++;
        }
        if (sum >= k) {
            ans = min(ans,q-i-1);
        }
    }
    cout << ans << "\n";
}
