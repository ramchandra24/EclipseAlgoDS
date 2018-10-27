def unb_knapsack(wt, val, W):
    dp = [0]*(W+1)
    dp[0] = 0
    
    for i in range(1, W+1):
        for j in range(0, len(wt)):
            if wt[j] <= i:
                dp[i] = max(dp[i], val[j] + dp[i-wt[j]])
    
    print "dp table : ", dp
    return dp[W]


val = [10, 30, 20] 
wt = [5, 10, 15]
res = unb_knapsack(wt, val, 100)
print "kp val : ", res