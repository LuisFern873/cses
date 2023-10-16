
# OPT(j): cantidad minima de monedas para formar la suma j

# OPT(j) = inf, j < 0
# OPT(j) = 0, j = 0
# OPT(j) = min{OPT(j - Ci) : 1 <= j <= n } + 1

def MINIZE_COINS(coins, suma):
    memo = [-1] * (suma + 1) 
    memo[0] = 0
    return MINIZE_COINS_AUX(coins, suma, memo)

def MINIZE_COINS_AUX(coins, suma, memo):

    if memo[suma] != -1:
        return memo[suma]
    
    if suma == 0:
        return 0
    
    q = float("inf")
    for i in range(0, len(coins)):
        if suma - coins[i] >= 0:
            q = min(q, MINIZE_COINS_AUX(coins, suma - coins[i], memo))
    memo[suma] = q + 1
    return memo[suma]

def BOTTOM_UP_MINIZE_COINS(coins, suma):
    memo = [0] * (suma + 1)
    
    for j in range(1, suma + 1):
        q = float("inf")
        for i in range(0, len(coins)):
            if j - coins[i] >= 0:
                q = min(q, memo[j - coins[i]] )
        memo[j] = q + 1
    return memo[suma]



n, suma = input().split()
n = int(n)
suma = int(suma)

coins = list(input().split())
coins = [int(x) for x in coins]

print(BOTTOM_UP_MINIZE_COINS(coins, suma))