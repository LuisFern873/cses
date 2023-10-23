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

    for (int k = 0; k < cuts.size(); k++) {
        if (i < cuts[k] and cuts[k] < j ) {
            q = min(q, OPT(i, cuts[k], cuts) + OPT(cuts[k], j, cuts));
        }
    }

    if (q == INT_MAX) {
        return 0;
    } else {
        return q + (j - i);
    }
}

// OPT(0, n)
int cutting_sticks(int l, const vector<int>& cuts)
{
    vector<vector<int>> dp(l + 1, vector<int>(l + 1, 0));

    for (int j = 1; j <= l; j++) {
        for (int i = )
    }

    return dp[0][l];
}
int main() {

    vector<int> cuts = {2, 4, 7};

    cout << OPT(0, 10, cuts) << endl;


    return 0;
}