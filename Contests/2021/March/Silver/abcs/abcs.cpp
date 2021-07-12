#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

bool check(vector<int> V, vector<int> C) {
    set<int> A;
    A.insert(C[0]); A.insert(C[1]); A.insert(C[2]);
    A.insert(C[0]+C[1]); A.insert(C[1]+C[2]); A.insert(C[0]+C[2]);
    A.insert(C[0]+C[1]+C[2]);
    for (auto x : V) {
        if (A.find(x) == A.end())
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> V(n);
        for (int i = 0; i < n; i++)
            cin >> V[i];
        sort(V.begin(),V.end());
        set<vector<int>> S;
        for (int i = 0; i < n; i++) {
            for (int q = 0; q < n; q++) {
                for (int r = 0; r < n; r++) {
                    vector<int> C(3);
                    C[0] = V[i]; C[1] = abs(V[q]-V[i]);
                    if (C[1] == 0) continue;
                    if (abs(C[0]+C[1]-V[r]) != 0) {
                        C[2] = abs(C[0]+C[1]-V[r]);
                    } else {
                        continue;
                    }
                    sort(C.begin(),C.end());
                    if (check(V,C))
                        S.insert(C);
                }
                for (int r = 0; r < n; r++) {
                    vector<int> C(3);
                    C[0] = V[i]; C[1] = abs(V[q]-V[i]);
                    if (C[1] == 0) continue;
                    if (abs(C[0]-V[r]) != 0) {
                        C[2] = abs(C[0]-V[r]);
                    } else {
                        continue;
                    }
                    sort(C.begin(),C.end());
                    if (check(V,C))
                        S.insert(C);
                }
                for (int r = 0; r < n; r++) {
                    vector<int> C(3);
                    C[0] = V[i]; C[1] = abs(V[q]-V[i]);
                    if (C[1] == 0) continue;
                    if (abs(C[1]-V[r]) != 0) {
                        C[2] = abs(C[1]-V[r]);
                    } else {
                        continue;
                    }
                    sort(C.begin(),C.end());
                    if (check(V,C))
                        S.insert(C);
                }
                for (int r = 0; r < n; r++) {
                    vector<int> C(3);
                    C[0] = V[i]; C[1] = abs(V[q]-V[i]); C[2] = V[r];
                    if (C[1] == 0) continue;
                    sort(C.begin(),C.end());
                    if (check(V,C))
                        S.insert(C);
                }
                for (int r = 0; r < n; r++) {
                    vector<int> C(3);
                    C[0] = V[i]; C[1] = V[q]; C[2] = V[r];
                    sort(C.begin(),C.end());
                    if (check(V,C))
                        S.insert(C);
                }
                for (int r = 0; r < n; r++) {
                    vector<int> C(3);
                    C[0] = abs(V[r]-V[i]); C[1] = abs(V[r]-V[q]); C[2] = abs(V[i]-C[1]);
                    if (C[0] == 0 || C[1] == 0 || C[2] == 0) continue;
                    sort(C.begin(),C.end());
                    if (check(V,C))
                        S.insert(C);
                }
            }
        }
        cout << S.size() << "\n";
    }
}
