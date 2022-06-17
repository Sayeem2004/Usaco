#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector< vector<int> > A(500);
vector<int> V(500);

bool dfs(int node, int goal) {
    if (node == goal) return true;
    V[node] = 1;
    bool fnd = false;
    for (int next : A[node]) {
        if (!V[next]) fnd |= dfs(next, goal);
    }
    V[node] = 0;
    return fnd;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        bool fnd = false;
        for (int q = 0; q < n; q++) {
            int x; cin >> x;
            if (x-1 == i) fnd = true;
            if (!fnd) A[i].push_back(x-1);
        }
    }
    for (int i = 0; i < n; i++) {
        bool br = false;
        for (int q = 0; q < A[i].size(); q++) {
            if (dfs(A[i][q], i)) {
                cout << A[i][q]+1 << "\n";
                br = true; break;
            }
        }
        if (!br) cout << i+1 << "\n";
    }
}
