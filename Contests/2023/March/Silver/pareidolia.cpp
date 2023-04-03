#include <bits/stdc++.h>
using namespace std;

vector<array<long long, 2>> findL(string str, string find) {
    vector<array<long long, 2>> RET;

    long long q = 0, l = -1;
    for (long long i = 0; i < str.size(); i++) {
        if (str[i] == find[q]) {
            q++; if (l == -1) l = i;
            if (q == find.size()) { RET.push_back({l, i}); l = -1; q = 0; }
        }
    }

    return RET;
}

vector<array<long long, 2>> findR(string str, string find) {
    vector<array<long long, 2>> RET;

    long long q = 5, r = -1;
    for (long long i = str.size()-1; i >= 0; i--) {
        if (str[i] == find[q]) {
            q--; if (r == -1) r = i;
            if (q == -1) { RET.push_back({i, r}); r = -1; q = 5; }
        }
    }

    return RET;
}

array<long long, 2> shrinkL(string str, string find, long long l, long long r) {
    long long q = find.size();
    for (long long i = r; i >= l; i--) {
        if (str[i] == find[q-1]) q--;
        if (q == 0) { l = i; break; }
    }
    return {l, r};
}

array<long long, 2> shrinkR(string str, string find, long long l, long long r) {
    long long q = 0;
    for (long long i = l; i <= r; i++) {
        if (str[i] == find[q]) q++;
        if (q == find.size()) { r = i; break; }
    }
    return {l, r};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    string S; cin >> S;
    string F = "bessie";

    vector<array<long long, 2>> LI = findL(S, F), RI = findR(S, F);
    for (array<long long, 2> &i : LI) i = shrinkL(S, F, i[0], i[1]);
    for (array<long long, 2> &i : RI) i = shrinkR(S, F, i[0], i[1]);

    set<array<long long, 2>> ITV;
    for (array<long long, 2> i : LI) ITV.insert(i);
    for (array<long long, 2> i : RI) ITV.insert(i);

    vector<array<long long, 2>> V(ITV.begin(), ITV.end());
    long long ans = 0;
    for (array<long long, 2> i : V) ans += (i[0] + 1) * (S.size() - i[1]);

    for (int i = 0; i < V.size(); i++) {
        for (int q = i+1; q < V.size(); q++) {
            if (V[i][1] > V[q][0]) ans -= (V[i][0] + 1) * (S.size() - V[q][1]);
        }
    }

    cout << ans << "\n";
}
