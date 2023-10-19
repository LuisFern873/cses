#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int OPT(int n, int m)
{
    if (n == m) {
        return 0;
    }

    int q = INT_MAX;

    for (int k = 1; k < n; k++) {
        q = min(q, OPT(k, m) + OPT(n - k, m));
    }

    for (int k = 1; k < m; k++) {
        q = min(q, OPT(n, k) + OPT(n, m - k));
    }

    return q + 1;
}

void print(const vector<vector<int>>& dp) 
{
    for (vector<int> row : dp) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

int rectangleCutting(int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == j) {
                dp[i][j] = 0;
            } else {
                int q = INT_MAX;
                for (int k = 1; k < i; k++) {
                    q = min(q, dp[k][j] + dp[i - k][j]);
                }
                for (int k = 1; k < j; k++) {
                    q = min(q, dp[i][k] + dp[i][j - k]);
                }
                dp[i][j] = q + 1;
            }
        }
    }

    return dp[n][m];
}



int main() {

    int n, m;
    cin >> n >> m;

    cout << rectangleCutting(n, m);

    return 0;
}