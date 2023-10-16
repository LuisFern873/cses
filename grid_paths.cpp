#include <iostream>
#include <vector>

using namespace std;

// Sea M[0...n-1][0....n-1] una cuadricula n x n
// Sea dp[i,j] el numero de caminos posibles para llegar desde M[i][j] a M[n-1][n-1]

int grid_paths(int i, int j, const vector<vector<char>>& M, int n)
{
    if (i == n or j == n or M[i][j] == '*') return 0;
    if (i == n - 1 and j == n - 1) return 1;

    return grid_paths(i + 1, j, M, n) + grid_paths(i, j + 1, M, n);
}

template <typename T>
void print(const vector<vector<T>>& grid) {
    for (vector<T> row : grid) {
        for (T elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

int grid_paths_dp(const vector<vector<char>>& M)
{
    int n = M.size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0)); // dp[i][j] = 0 para todo i = n o j = n

    dp[n - 1][n - 1] = 1;

    for (int j = n - 2; j >= 0; j--) {
        if (M[n - 1][j] == '*') dp[n - 1][j] = 0;
        else dp[n - 1][j] = dp[n - 1 + 1][j] + dp[n - 1][j + 1];
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (M[i][j] == '*') dp[i][j] = 0;
            else dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
        }
    }

    return dp[0][0];
}


/*
n = 3

dp[0...n][0...n]
6 3 1 0
3 2 1 0
1 1 1 0
0 0 0 0 <- i = n -1

Llenar de forma diagonal:
dp[i,j] = dp[i + 1,j] + dp[i,j + 1]

*/

int main() {
    int n;
    cin >> n;
    
    string s;

    vector<vector<char>> M(n, vector<char>(n));

    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) {
            M[i][j] = s[j];
        }
    }

    // vector<vector<char>> M = {
    //     {'.', '*', '.', '.'},
    //     {'.', '*', '.', '.'},
    //     {'.', '.', '.', '*'},
    //     {'*', '.', '.', '.'}
    // };

    // print(M);

    cout << grid_paths_dp(M) << endl;

    return 0;
}