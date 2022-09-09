/*
ID: mohamma176
TASK: transform
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

bool compare(vector<string> &A, vector<string> &B, int n) {
    for (int i = 0; i < n; i++) {
        for (int q = 0; q < n; q++) {
            if (A[i][q] != B[i][q]) return false;
        }
    }
    return true;
}

vector<string> rotate(vector<string> &A, int n, int mode) {
    vector<string> B(n, string(n, ' '));
    if (mode == 0) {
        for (int i = 0; i < n; i++) {
            B[i] = A[i];
        }
    } else if (mode == 1) {
        for (int i = 0; i < n; i++) {
            for (int q = 0; q < n; q++) {
                B[i][q] = A[n - 1 - q][i];
            }
        }
    } else if (mode == 2) {
        for (int i = 0; i < n; i++) {
            for (int q = 0; q < n; q++) {
                B[i][q] = A[n - 1 - i][n - 1 - q];
            }
        }
    } else if (mode == 3) {
        for (int i = 0; i < n; i++) {
            for (int q = 0; q < n; q++) {
                B[i][q] = A[q][n - 1 - i];
            }
        }
    }
    return B;
}

vector<string> reflect(vector<string> &A, int n) {
    vector<string> B(n, string(n, ' '));
    for (int i = 0; i < n; i++) {
        for (int q = 0; q < n; q++) {
            B[i][q] = A[i][n - 1 - q];
        }
    }
    return B;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("transform.in","r",stdin);
    freopen("transform.out","w",stdout);
    int n; cin >> n;
    vector<string> A(n), B(n);
    for (string &a : A) cin >> a;
    for (string &b : B) cin >> b;
    vector<string> R1 = rotate(A, n, 1), R2 = rotate(A, n, 2), R3 = rotate(A, n, 3);
    vector<string> C1 = reflect(A, n), C2 = reflect(A, n), C3 = reflect(A, n), C4 = reflect(A, n);
    C1 = rotate(C1, n, 1), C2 = rotate(C2, n, 2), C3 = rotate(C3, n, 3);
    if (compare(B, R1, n)) cout << 1 << "\n";
    else if (compare(B, R2, n)) cout << 2 << "\n";
    else if (compare(B, R3, n)) cout << 3 << "\n";
    else if (compare(B, C4, n)) cout << 4 << "\n";
    else if (compare(B, C1, n) || compare(B, C2, n) || compare(B, C3, n)) cout << 5 << "\n";
    else if (compare(B, A, n)) cout << 6 << "\n";
    else cout << 7 << "\n";
}
