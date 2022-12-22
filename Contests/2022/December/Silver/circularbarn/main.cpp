#include <bits/stdc++.h>
using namespace std;

vector<int> sieve(int n) {
    vector<int> S(n+1, true);
    S[0] = S[1] = 1;

    for (int i = 2; i <= n; i++) {
        if (S[i] == 0) {
            for (int j = i; j <= n; j += i)
                S[j] = i;
        }
    }

    return S;
}

int moves(int n, vector<int> &S) {
    if (n == 0 || n == 1) return 0;
    if (n == 2) return 1;

    if (n % 2 == 0) return 2;
    if (S[n] == n) return 1;
    if (S[n-2] == n-2) return 2;

    return 3;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        vector<int> S = sieve(5000000);

        vector<int> M(n);
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            M[i] = moves(x, S);
        }

        // curr: true = john, false = nhoj
        bool curr = true, br = false;
        for (int i = 0; i < n; i++) {
            if (M[i] == 0) {
                br = true;
                break;
            }

            if (M[i] == 1) {
                curr = !curr;
                M[i] = 0;

                br = true;
                break;
            }

            if (M[i] == 2) {
                M[i] = 0;
            }

            if (M[i] == 3) {
                M[i] = 1;
            }
        }

        if (br) {
            cout << "Farmer " << (curr ? "Nhoj" : "John") << "\n";
            continue;
        }

        for (int i = 0; i < n; i++) {
            if (M[i] == 0) {
                br = true;
                break;
            }

            if (M[i] == 1) {
                curr = !curr;
                M[i] = 0;

                br = true;
                break;
            }

            if (M[i] == 2) {
                M[i] = 0;
            }

            if (M[i] == 3) {
                M[i] = 1;
            }
        }

        if (br) {
            cout << "Farmer " << (curr ? "Nhoj" : "John") << "\n";
            continue;
        }

        cout << "Farmer " << (curr ? "John" : "Nhoj") << "\n";
    }
}
