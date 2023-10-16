#include <iostream>
#include <vector>
#include <climits>
using namespace std;


#define ll long long

// OPT(j) = min{OPT(j - Ci) : 1 <= i <= j}

void print(const vector<ll>& v) {
    for (ll a : v) {
        cout << a << " ";
    }
    cout << endl;
}
ll MINIMIZE_COINS(ll n, const vector<ll>& coins, ll suma) {

    vector<ll> memo(suma + 1);
    memo[0] = 0;

    ll q;

    for (int j = 1; j <= suma; j++){
        // print(memo);
        q = INT_MAX;

        for (int i = 0; i < n; i++){
            if (j - coins[i] >= 0) {
                q = min(q, memo[j - coins[i]]);
            }
        }
        memo[j] = q + 1;
    }

    return (memo[suma] - (ll)INT_MAX == 1 ? -1 : memo[suma]);
}

int main() {

    ll n, x;
    ll coin_value;
    vector<ll> coins;

    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> coin_value;
        coins.push_back(coin_value);
    }

    cout << MINIMIZE_COINS(n, coins, x);



    return 0;
}