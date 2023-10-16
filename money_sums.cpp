#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void print(const vector<T>& v)
{
    for (T i : v) {
        cout << i << " "; 
    }
    cout << "\n";
}

int money_sums(int n, int current, vector<int> coins, vector<bool>& visited)
{

    if (n == 1) {
        visited[coins[0]] = true;
        return 1;
    }
    int sums = 0;

    for (int i = 0; i < coins.size(); i++) {
        current += coins[i]; // 2
        if (visited[current] == false) {
            visited[current] = true;
            coins.erase(coins.begin() + i);
            sums += money_sums(n - 1, current, coins, visited);
        }
    }
    return sums;
}

int main() {
    int n, x, c;
    vector<int> coins = {};

    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        cin >> c;
        coins.push_back(c);
    }

    vector<bool> visited(x + 1, false);
    visited[0] = true;

    money_sums(n, 0, coins, visited);

    print(visited);

    return 0;
}