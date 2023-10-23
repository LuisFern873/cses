#include <iostream>
#include <vector>

using namespace std;

#define ll long long

const ll mod = 1e9 + 7;

/*
OPT(j): number of ways to construct the sum j by throwing a dice one or more times
OPT(j) = 1, j = 0
OPT(j) = Σ OPT(j - i), i = 1 to min(j, 6), j > 0
*/

ll count_ways(ll n) {
    vector<ll> memo(n + 1);
    memo[0] = 1;

    ll ways;

    for (int j = 1; j <= n; j++) {
        ways = 0;
        for (int i = 1; i <= min(j, 6); i++) {
            ways += memo[j - i];
        }
        memo[j] = ways % mod;
    }
    return memo[n];
}

int main() {
    ll n;
    cin >> n;
    cout << count_ways(n);

    return 0;
}