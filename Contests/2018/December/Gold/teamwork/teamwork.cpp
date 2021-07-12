#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int n;  // array size
int ST[400000];

void build() {  // build the tree
    for (int i = n - 1; i > 0; --i)
        ST[i] = max(ST[i<<1], ST[i<<1|1]);
}

int getrange(int l, int r) {  // get on interval [l, r)
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = max(res, ST[l++]);
        if (r&1) res = max(res, ST[--r]);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("teamwork.in","r",stdin);
    freopen("teamwork.out","w",stdout);
    int k; cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> ST[n+i];
    build();
    vector<int> DP(n+1);
    for (int i = 1; i <= n; i++) {
        for (int q = max(i-k, 0); q < i; q++) {
            DP[i] = max(DP[i], DP[q] + (i-q)*getrange(q,i));
        }
    }
    cout << DP[n] << "\n";
}
