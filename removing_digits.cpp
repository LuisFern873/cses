#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
#include <unordered_map>

using namespace std;

// OPT(n): minima cantidad de pasos para llegar a 0, sustrayendo un digito de un numero n
// OPT(n) = 1, n es un numero de un digito
// OPT(n) = min{OPT(i - digit_j) : 1 <= j <= n} + 1, cc

int getDigit(int n, int position) {
    int divisor = 1;
    for (int i = 0; i < position; i++) {
        divisor *= 10;
    }
    return (n / divisor) % 10;
}
int countDigits(int n) {
    int count = 0;
    if (n == 0) {
        return 1;
    }
    
    while (n != 0) {
        n = n / 10;
        count++;
    }
    
    return count;
}

int OPT_aux(int n, unordered_map<int, int>& memo)
{

    if (memo.find(n) != memo.end()) {
        return memo[n];
    }

    if (countDigits(n) == 1) {
        return 1;
    }

    int q = INT_MAX;

    for (int i = 0; i < countDigits(n); i++) {
        int digit = getDigit(n, i);
        if (digit != 0) {
            q = min(q, OPT_aux(n - digit, memo));
        }
    }

    memo[n] = q + 1;

    return memo[n];
}

int OPT(int n)
{
    unordered_map<int, int> memo;

    return OPT_aux(n, memo);
}




int main() {
    int n;
    cin >> n;
    cout << OPT(n);

    return 0;
}