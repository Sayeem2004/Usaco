#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    long long N; cin >> N;
    vector<long long> V(N), S(N);
    for (int i = 0; i < N; i++) {
        cin >> V[i];
        S[i] = V[i];
    }
    sort(S.begin(), S.end());

    vector<long long> P(N+1), PM(N+1);
    for (int i = 0; i < N; i++) {
        P[i+1] = P[i] + S[i];
        PM[i+1] = PM[i] + S[i] * (i + 1);
    }

    long long Q; cin >> Q; while (Q--) {
        long long pos, nval; cin >> pos >> nval; pos--;
        long long val = V[pos];

        long long spos = (lower_bound(S.begin(), S.end(), val) - S.begin()) + 1;
        long long npos = (lower_bound(S.begin(), S.end(), nval) - S.begin()) + 1;
        if (npos > spos) npos--;

        long long ans = PM[N] - val * spos + nval * npos;
        if (npos < spos) ans += P[spos-1] - P[npos-1];
        else if (npos > spos) ans -= P[npos] - P[spos];

        cout << ans << "\n";
    }
}
