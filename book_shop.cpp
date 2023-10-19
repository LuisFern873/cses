#include <iostream>
#include <vector>

using namespace std;

// Recuerda Subset sum
// OPT(n, W) = 0 si n = 0
// OPT(n, W) = OPT(n - 1, W) si n > 0 y wn > W 
// OPT(n, W) = max(OPT(n - 1, W), OPT(n - 1, W - wn) + wn) si n > 0 y wn <= W


// n books price y pages

// p1 + p2 + p3 + <= x

// Definimos para book shop el siguiente OPT
// Problema resuelto en 25 min :-)

int OPT(int n, int x, const vector<int>& prices, const vector<int>& pages)
{
    if (n == 0) {
        return 0;
    }

    // n - 1, la indexacion de prices y pages comienza en 0
    if (prices[n - 1] > x) {
        return OPT(n - 1, x, prices, pages);
    } else { // prices[n] <= x
        return max(OPT(n - 1, x, prices, pages), OPT(n - 1, x - prices[n - 1], prices, pages) + pages[n - 1]);
    }
}


int book_shop(int n, int x, const vector<int>& prices, const vector<int>& pages)
{
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            if (prices[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - prices[i - 1]] + pages[i - 1]);
            }

        }
    }

    return dp[n][x];
}


int main() {

    int n, x;

    cin >> n >> x;

    int price, page;

    vector<int> prices = {};
    vector<int> pages = {};

    for (int i = 0; i < n; i++){
        cin >> price;
        prices.push_back(price);
    }

    for (int i = 0; i < n; i++){
        cin >> page;
        pages.push_back(page);
    }

    cout << book_shop(n, x, prices, pages) << endl;

    return 0;
}