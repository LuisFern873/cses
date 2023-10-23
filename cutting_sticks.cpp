#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// OPT(i, j) = 0, j = i + 1
// OPT(i, j) = min(OPT(i, k) + OPT(k, j) : i < k < j) + (j - i) j > i + 1

int OPT(int i, int j, const vector<int>& cuts)
{
    if (j - i == 1) {
        return 0;
    }

    int q = INT_MAX;

    for (int k : cuts) {
        if (i < k and k < j) {
            q = min(q, OPT(i, k, cuts) + OPT(k, j, cuts));
        }
    }

    if (q == INT_MAX) {
        return 0;
    } else {
        return q + (j - i);
    }
}

template <typename T>
void print(const vector<vector<T>>& dp) {
    for (vector<T> row : dp) {
        for (T value : row) {
            cout << value << " ";
        }
        cout << endl;
    }
}

int cutting_sticks(int l, const vector<int>& cuts)
{
    vector<vector<int>> dp(l + 1, vector<int>(l + 1, 0));

    for (int j = 2; j <= l; j++) {
        for (int i = j - 2; i >= 0; i--) {
            int q = INT_MAX;
            for (int k : cuts) {
                if (i < k and k < j) {
                    q = min(q, dp[i][k] + dp[k][j]);
                }
            }
            if (q == INT_MAX) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = q + (j - i);
            }
        }
    }

    print(dp);

    return dp[0][l];
}

int main() {
    int l = 10;
    vector<int> cuts = {2, 4, 7};
    cout << cutting_sticks(l, cuts) << endl;
    return 0;
}