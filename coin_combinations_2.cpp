#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void print(const vector<int>& vec)
{
    for (int i : vec) {
        cout << i << " ";
    }
    cout << "\n";
}


int combinations(int x, vector<int> coins, unordered_map<int, int>& memo)
{
    if (x == 0) {
        return 1;
    }

    // if (memo.find(x) != memo.end()) {
    //     return memo[x];
    // }

    int ways = 0;

    for (int i = 0; i < coins.size(); i++) {
        if (x - coins[i] >= 0) {
            // OPT(n, C) =  Σ OPT(x - C[i], C[i...n])
            ways += combinations(x - coins[i], vector<int>(coins.begin() + i, coins.end()), memo);
        }
    }
    // memo[x] = ways;

    return ways;
}

int main() {
    int n, x, c;
    vector<int> coins = {};

    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        cin >> c;
        coins.push_back(c);
    }

    unordered_map<int, int> memo;
    memo[0] = 1;

    cout << combinations(x, coins, memo) << endl;

    // remove(1, coins);
    // print(coins);

    return 0;
}