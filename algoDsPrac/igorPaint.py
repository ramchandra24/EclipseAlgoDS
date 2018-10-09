class node:
    def __init__(self):
        self.val = 0
        self.index = 0
        
    def printNode(self):
        print self.index, " : ", self.val
        
def unb_knapsack(arr, W):
    import sys
    dp = [sys.maxsize]*(W+1)
    dp[0] = 0

    op_arr = [node() for i in range(W+1)]
    
    for i in range(1, W+1):
        for j in range(0, len(arr)):
            if arr[j].val <= i:
                curr = dp[i]
                dp[i] = min(dp[i], arr[j].val + dp[i-arr[j].val])
                if curr != dp[i]:
                    op_arr[i].index = arr[j].index
                    op_arr[i].val = arr[j].val
    i = W
    ret_arr = []
    while i > 0:
        ret_arr.append( op_arr[i].index )
        i -= op_arr[i].val
    return ret_arr


def cond(a, b):
    diff = a.val - b.val
    if 0 == diff:
        return b.index - a.index
    return diff


v = int(raw_input())
a = map(int, raw_input().split(' '))

if v == 0:
    print "-1"
else:
    arr = []
    for i in range(len(a)):
        an = node()
        an.index = i+1
        an.val = a[i]
        arr.append(an)
        
    arr = sorted(arr, cmp = cond)
    if v < arr[0].val:
        print "-1"
    
    else:
        res = unb_knapsack(arr, v)
        res = sorted(res, reverse=True)
        print "".join(map(str, res))