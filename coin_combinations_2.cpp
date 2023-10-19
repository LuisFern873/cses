#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

#define ll long long
const int mod = 1e9+7;

int combinations(int x, vector<ll> coins)
{
    if (x == 0) {
        return 1;
    }
    int ways = 0;

    for (int i = 0; i < coins.size(); i++) {
        if (x - coins[i] >= 0) {
            // OPT(n, C) =  Σ OPT(x - C[i], C[i...n])
            ways += combinations(x - coins[i], vector<ll>(coins.begin() + i, coins.end()));
        }
    }

    return ways;
}

void print(const vector<int>& vec)
{
    for (int i : vec) {
        cout << i << " ";
    }
    cout << "\n";
}

int dp(int x, const vector<ll>& coins)
{
    int n = coins.size();
    vector<ll> memo(x + 1, 0); 
    memo[0] = 1;
        
    for (int i = 0; i < n; i++) { // C[i]
        for (int j = 1; j <= x; j++) {
            if (j - coins[i] >= 0) {
                // OPT(n, C) =  Σ OPT(x - C[i], C[i...n])
                memo[j] = (memo[j] + memo[j - coins[i]]) % mod;
            }
        }
    }

    // print(memo);

    return memo[x];
}

int main() {
    int n, x;
    ll c;
    vector<ll> coins = {};

    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        cin >> c;
        coins.push_back(c);
    }

    unordered_map<int, int> memo;
    memo[0] = 1;

    cout << dp(x, coins) << endl;
    cout << endl;
    cout << combinations(x, coins) << endl;

    // remove(1, coins);
    // print(coins);

    return 0;
}