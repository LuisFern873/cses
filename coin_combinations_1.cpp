#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


// Input: C[n], x
// Output: number of distinct ways you can produce a money sum x using the available coins C.
// OPT(0) = 1
// OPT(x) = Σ {i ∈ C} OPT(x - i)

int count_aux(int x, const vector<int>& coins, vector<int>& memo)
{
    if (memo[x] != -1) {
        return memo[x];
    }
    if (x == 0) {
        return 1;
    }
    int ways = 0;
    for (int value : coins) {
        if (x - value >= 0) {
            ways += count_aux(x - value, coins, memo);
        }
    }
    memo[x] = ways;

    return memo[x];
}

int count(int x, const vector<int>& coins) {
    vector<int> memo(x + 1, -1);
    memo[0] = 1;
    return count_aux(x, coins, memo) % 1000000007;
}

int main() {
    int n, x, c;
    vector<int> coins = {};

    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        cin >> c;
        coins.push_back(c);
    }

    cout << count(x, coins);

    return 0;
}