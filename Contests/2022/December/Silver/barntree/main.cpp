#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<array<int, 2>, vector<array<int, 3>>> a, pair<array<int, 2>, vector<array<int, 3>>> b) {
    return a.first[1] < b.first[1];
}

// arr[0] = child node, arr[1] = what child node needs
pair<array<int, 2>, vector<array<int, 3>>> helper(int n, int p, vector<bool> &V, vector<vector<int>> &A, vector<int> &H, int v) {
    if (V[n]) return {{n, 0}, {}};
    V[n] = true;

    vector<pair<array<int, 2>, vector<array<int, 3>>>> T;
    for (int i : A[n]) {
        if (i == p) continue;
        pair<array<int, 2>, vector<array<int, 3>>> C = helper(i, n, V, A, H, v);
        T.push_back(C);
    }

    sort(T.begin(), T.end(), cmp);
    vector<array<int, 3>> R;
    // cout << T.size() << "\n";
    for (int i = 0; i < T.size(); i++) {
        if (T[i].first[1] < 0) {
            for (int q = 0; q < T[i].second.size(); q++) {
                R.push_back(T[i].second[q]);
            }
            R.push_back({T[i].first[0], n, T[i].first[1] * -1});
            H[n] -= T[i].first[1];
        } else if (T[i].first[1] == 0) {
            for (int q = 0; q < T[i].second.size(); q++) {
                R.push_back(T[i].second[q]);
            }
        } else {
            R.push_back({n, T[i].first[0], T[i].first[1]});
            for (int q = 0; q < T[i].second.size(); q++) {
                R.push_back(T[i].second[q]);
            }
            H[n] -= T[i].first[1];
        }
    }

    // cout << n+1 << " " << v - H[n] << "\n";
    // for (int i = 0; i < R.size(); i++) {
    //     cout << R[i][0]+1 << " " << R[i][1]+1 << " " << R[i][2] << "\n";
    // }
    // cout << "\n";
    return {{n, v - H[n]}, R};
}

vector<array<int, 3>> dfs(int n, int p, vector<bool> &V, vector<vector<int>> &A, vector<int> &H, int v) {
    pair<array<int, 2>, vector<array<int, 3>>> ret = helper(n, p, V, A, H, v);
    return ret.second;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> H(n);
    int sm = 0;
    for (int i = 0; i < n; i++) {
        cin >> H[i];
        sm += H[i];
    }

    vector<bool> V(n);
    vector<vector<int>> A(n);
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        A[a].push_back(b);
        A[b].push_back(a);
    }

    int pos = -1, mx = -1;
    for (int i = 0; i < n; i++) {
        if (A[i].size() == 1) {
            if (H[i] > mx) {
                mx = H[i];
                pos = i;
            }
        }
    }

    // for (int i = 0; i < A.size(); i++) {
    //     for (int q : A[i]) {
    //         cout << q+1 << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";

    vector<array<int, 3>> R = dfs(pos, -1, V, A, H, sm/n);
    cout << R.size() << "\n";
    for (int i = 0; i < R.size(); i++) {
        cout << R[i][0]+1 << " " << R[i][1]+1 << " " << R[i][2] << "\n";
    }
}
