#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int n;  // array size
int ST[400000];

void build() {  // build the tree
    for (int i = n - 1; i > 0; --i)
        ST[i] = min(ST[i<<1], ST[i<<1|1]);
}

int getrange(int l, int r) {  // get on interval [l, r)
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = min(ST[l++], res);
        if (r&1) res = min(ST[--r], res);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("homework.in","r",stdin);
    freopen("homework.out","w",stdout);
    int n; cin >> n;
    int sm = 0;
    for (int i = 0; i < n; i++) {
        cin >> ST[i+n];
        sm += ST[i+n];
    }
    build();
    vector<double> M(n, 0.0);
    for (int i = 0; i < n-2; i++) {
        sm -= ST[i+n];
        M[i] = (double)(sm-getrange(i+1, n)) / (n-i-1);
    }
    double mx = 0.0;
    for (int i = 0; i < n; i++) {
        mx = max(M[i], mx);
    }
    for (int i = 0; i < n; i++) {
        if (mx == M[i]) cout << i+1 << "\n";
    }
}
