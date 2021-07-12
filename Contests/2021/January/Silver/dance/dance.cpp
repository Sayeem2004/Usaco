#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    int n, q; cin >> n >> q;
    vector<pair<int,int>> moves(q);
    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        moves[i] = make_pair(a-1,b-1);
    }
    vector<vector<int>> visited(n,vector<int>(n,0));
    vector<int> count(n,1);
    for (int i = 0; i < n; i++) {
        visited[i][i] = 1;
    }
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        pos[i] = i;
    }
    int i = 0;
    while (i < 1000000) {
        int a = moves[i%q].first;
        int b = moves[i%q].second;
        int c = pos[a];
        if (!visited[pos[a]][b]) {
            count[pos[a]]++;
            visited[pos[a]][b] = 1;
        }
        pos[a] = pos[b];
        if (!visited[pos[b]][a]) {
            count[pos[b]]++;
            visited[pos[b]][a] = 1;
        }
        pos[b] = c;
        i++;
    }
    for (auto x : count) {
        cout << x << "\n";
    }
}
