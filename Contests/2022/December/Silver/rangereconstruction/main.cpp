#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int mx = 0;
    vector<int> D(n-1);
    for (int i = n; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            int x; cin >> x;
            mx = max(mx, x);
            if (j == 1) D[n-i] = x;
        }
    }
    vector<int> A(n);
    A[0] = 0;
    for (int i = 1; i < n; i++) {
        if (A[i-1] + D[i-1] > mx) {
            A[i] = A[i-1] - D[i-1];
        } else {
            A[i] = A[i-1] + D[i-1];
        }
    }
    for (int i = 0; i < n; i++) {
        cout << A[i] << " \n"[i == n-1];
    }
}
