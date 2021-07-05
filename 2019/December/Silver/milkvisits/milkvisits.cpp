#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
vector<char> T(100000);
vector<int> V(100000);
vector<vector<int>> A(100000);

void dfs(int v, int p, int t) {
    V[v] = t;
    for (auto x : A[v]) {
        if (x == p) continue;
        if (!V[x]) {
            if (T[x] == T[v]) dfs(x, v, t);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("milkvisits.in","r",stdin);
    freopen("milkvisits.out","w",stdout);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> T[i];
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        A[a-1].push_back(b-1);
        A[b-1].push_back(a-1);
    }
    for (int i = 0, q = 0; i < n; i++) {
        if (!V[i]) {
            q++;
            dfs(i, -1, q);
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        char c; cin >> c;
        if (V[a-1] != V[b-1] || T[a-1] == c || T[b-1] == c) cout << 1;
        else cout << 0;
    }
    cout << "\n";
}
