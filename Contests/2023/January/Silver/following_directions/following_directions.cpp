#include <bits/stdc++.h>
using namespace std;

int ind(int i, int q, int N) {
    return i * N + q;
}

int row(int v, int N) {
    return v / N;
}

int col(int v, int N) {
    return v % N;
}

int init_dfs(int v, vector<vector<int>> &COST, vector<vector<int>> &ADJ, int N) {
    if (COST[row(v, N)][col(v, N)] > -1) {
        return COST[row(v, N)][col(v, N)];
    }

    int ans = 0;
    for (int u : ADJ[v]) {
        ans = max(ans, init_dfs(u, COST, ADJ, N));
    }

    COST[row(v, N)][col(v, N)] = ans;
    return ans;
}

void update_dfs(int v, vector<vector<int>> &COST, vector<vector<int>> &RDJ, int N, int nc, int &TOTAL) {
    TOTAL -= COST[row(v, N)][col(v, N)];
    COST[row(v, N)][col(v, N)] = nc;
    TOTAL += COST[row(v, N)][col(v, N)];

    for (int u : RDJ[v]) {
        update_dfs(u, COST, RDJ, N, nc, TOTAL);
    }
}
int main() {
    // Fast I/O.
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // Data variables.
    int N; cin >> N;
    vector<string> GRID(N);
    vector<int> RGT(N), DWN(N);

    // Reading in data
    for (int i = 0; i < N; i++) {
        cin >> GRID[i];
        cin >> RGT[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> DWN[i];
    }

    // Query variables
    int Q; cin >> Q;
    vector<array<int, 2>> SWAP(Q);

    // Reading in queries.
    for (int i = 0; i < Q; i++) {
        cin >> SWAP[i][0] >> SWAP[i][1];
    }

    // Creating adjacency and reverse lists.
    vector<vector<int>> ADJ((N+1)*(N+1)), RDJ((N+1)*(N+1));
    for (int i = 0; i < N; i++) {
        for (int q = 0; q < N; q++) {
            if (GRID[i][q] == 'D') {
                ADJ[ind(i, q, N+1)].push_back(ind(i+1, q, N+1));
                RDJ[ind(i+1, q, N+1)].push_back(ind(i, q, N+1));
            }

            if (GRID[i][q] == 'R') {
                ADJ[ind(i, q, N+1)].push_back(ind(i, q+1, N+1));
                RDJ[ind(i, q+1, N+1)].push_back(ind(i, q, N+1));
            }
        }
    }

    // Printing out the adjacency and reverse lists.
    // for (int i = 0; i < N+1; i++) {
    //     for (int q = 0; q < N+1; q++) {
    //         cout << ind(i, q, N+1) << ": ";
    //         for (int u : ADJ[ind(i, q, N+1)]) {
    //             cout << u << " ";
    //         }
    //         cout << "\n";
    //     }
    // }
    // cout << "\n";
    // for (int i = 0; i < N+1; i++) {
    //     for (int q = 0; q < N+1; q++) {
    //         cout << ind(i, q, N+1) << ": ";
    //         for (int u : RDJ[ind(i, q, N+1)]) {
    //             cout << u << " ";
    //         }
    //         cout << "\n";
    //     }
    // }
    // cout << "\n";


    // Creating cost array.
    vector<vector<int>> COST(N+1, vector<int>(N+1, -1));
    for (int i = 0; i < N; i++) {
        for (int q = 0; q < N; q++) {
            COST[i][q] = -1;
        }
    }
    for (int i = 0; i < N; i++) {
        COST[i][N] = RGT[i];
        COST[N][i] = DWN[i];
    }
    COST[N][N] = 0;

    // Filling in the cost array.
    for (int i = 0; i < N; i++) {
        for (int q = 0; q < N; q++) {
            if (COST[i][q] == -1) {
                init_dfs(ind(i, q, N+1), COST, ADJ, N+1);
            }
        }
    }

    // Printing out the cost array.
    // for (int i = 0; i < N+1; i++) {
    //     for (int q = 0; q < N+1; q++) {
    //         cout << COST[i][q] << " ";
    //     }
    //     cout << "\n";
    // }

    // Getting initial cost.
    int TOTAL = 0;
    for (int i = 0; i < N; i++) {
        for (int q = 0; q < N; q++) {
            TOTAL += COST[i][q];
        }
    }
    cout << TOTAL << "\n";

    // Performing queries.
    for (int i = 0; i < Q; i++) {
        int r = SWAP[i][0] - 1;
        int c = SWAP[i][1] - 1;
        int nc;

        if (GRID[r][c] == 'D') {
            GRID[r][c] = 'R';
            nc = COST[r][c+1];

            ADJ[ind(r, c, N+1)].pop_back();
            ADJ[ind(r, c, N+1)].push_back(ind(r, c+1, N+1));

            for (int q = 0; q < RDJ[ind(r+1, c, N+1)].size(); q++) {
                if (RDJ[ind(r+1, c, N+1)][q] == ind(r, c, N+1)) {
                    RDJ[ind(r+1, c, N+1)].erase(RDJ[ind(r+1, c, N+1)].begin() + q);
                    break;
                }
            }
            RDJ[ind(r, c+1, N+1)].push_back(ind(r, c, N+1));
        } else {
            GRID[r][c] = 'D';
            nc = COST[r+1][c];

            ADJ[ind(r, c, N+1)].pop_back();
            ADJ[ind(r, c, N+1)].push_back(ind(r+1, c, N+1));

            for (int q = 0; q < RDJ[ind(r, c+1, N+1)].size(); q++) {
                if (RDJ[ind(r, c+1, N+1)][q] == ind(r, c, N+1)) {
                    RDJ[ind(r, c+1, N+1)].erase(RDJ[ind(r, c+1, N+1)].begin() + q);
                    break;
                }
            }
            RDJ[ind(r+1, c, N+1)].push_back(ind(r, c, N+1));
        }

        update_dfs(ind(r, c, N+1), COST, RDJ, N+1, nc, TOTAL);

        cout << TOTAL << "\n";
    }
}
