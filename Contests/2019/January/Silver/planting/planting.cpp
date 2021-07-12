#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("planting.in","r",stdin);
    freopen("planting.out","w",stdout);
    int n; cin >> n;
    vector<vector<int>> A(n);
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        A[a-1].push_back(b-1);
        A[b-1].push_back(a-1);
    }
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int c = A[i].size();
        mx = max(mx, c+1);
    }
    cout << mx << "\n";
}
