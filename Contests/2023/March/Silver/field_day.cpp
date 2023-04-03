#include <bits/stdc++.h>
using namespace std;

int convert(string s) {
    int ans = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'H') ans += 1 << i;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int C, N; cin >> C >> N;
    vector<int> V(N);
    set<int> ST;

    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        V[i] = convert(s);
        ST.insert(V[i]);
    }

    map<int, int> M;
    for (int i = 0; i < (1 << C); i++) {
        for (int q = 0; q < (1 << C); q++) {
            if (ST.count(i) && ST.count(q)) {
                int dif = __builtin_popcount(i ^ q);
                M[i] = max(M[i], dif);
                M[q] = max(M[q], dif);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << M[V[i]] << "\n";
    }
}
