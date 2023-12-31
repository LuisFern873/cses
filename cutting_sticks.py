

# The cost to make a cut is the same as the size of the stick

# 2, 4 and 7 

# cuts = [2, 4, 7]
# OPT(i, j, C) = 0  (no cuts, Ci >= j)
# OPT(i, j) = min(OPT(i, k) + OPT(k, j)) + (j - i)

def OPT(i, j, cuts):

    if len(cuts) == 0:
        return 0
    
    q = float("inf")

    for k in range(0, len(cuts)):
        q = min(q, OPT(i, cuts[k], cuts[:k]) + OPT(cuts[k], j, cuts[k+1:]))

    return q + (j - i)

def DP(i, j):

    if j - i == 1:
        return 0
    
    q = float("inf")
    for cut in cuts:
        if i < cut < j:
            q = min(q, DP(i, cut) + DP(cut, j))
    
    if q == float("inf"):
        return 0
    else:
        return q + (j - i)
    
cuts = [2, 4]

print(DP(0, 10))
