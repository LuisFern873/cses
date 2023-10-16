#include <iostream>
#include <vector>

using namespace std;

/*
OPT(j): number of ways to construct the sum j 
by throwing a dice one or more times

OPT(0) = 1, j = 0
OPT(j) = Σ OPT(j - i), i = 1 to min(j, 6), dj > 0
*/

// long long count_ways_aux(long long n, vector<long long>& memo)
// {
//     if (memo[n] != -1) {
//         return memo[n];
//     }

//     if (n == 0) {
//         return 1;
//     }

//     long long ways = 0;

//     for (int i = 1; i <= min(n, (long long) 6); i++) {
//         ways += count_ways_aux(n - i, memo);
//     }
//     return ways;
// }

long long count_ways(long long n) {
    vector<long long> memo(n + 1);
    memo[0] = 1;

    long long ways;

    for (long long j = 1; j <= n; j++) {
        ways = 0;
        for (long long i = 1; i <= min(j, (long long) 6); i++) {
            ways += memo[j - i];
        }
        memo[j] = ways;
    }
    return memo[n] % 1000000007;
}

int main() {

    long long n;

    // n = 4

    // 1 + 1 + 1 + 1
    // 1 + 1 + 2
    // 1 + 2 + 1
    // 1 + 3

    // 2 + 1 + 1
    // 2 + 2
    // 3 + 1
    // 4

    cin >> n;

    cout << count_ways(n);

    
    
    return 0;
}