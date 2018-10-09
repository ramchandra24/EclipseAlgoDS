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

    val_arr = [0]*(W+1)
    op_arr = [node() for i in range(W+1)]
    
    for i in range(1, W+1):
        for j in range(0, len(arr)):
            if arr[j].val <= i:
                curr = dp[i]
                dp[i] = min(dp[i], arr[j].val + dp[i-arr[j].val])
                if curr != dp[i]:
                    val_arr[i] = arr[j].index
                    op_arr[i].index = arr[j].index
                    op_arr[i].val = arr[j].val
            #print val_arr
    #print "dp table : ", dp
    #for op in op_arr:
    #    print op.index, ":", op.val
    i = W
    ret_arr = []
    while i > 0:
#        ret_arr.append( val_arr[i] )
#        i -= val_arr[i]
    #print "dp table : ", dp
        ret_arr.append( op_arr[i].index )
        i -= op_arr[i].val
    #print "dp table : ", dp
    return ret_arr


def cond(a, b):
    #print "comparing : ", a.val, " with ", b.val
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
    #for cl in arr:
    #    cl.printNode()
    if v < arr[0].val:
        print "-1"
    
    else:
        #---------------------------------------- num_of_digits = v / arr[0].val
        #-------------------------------------------- #print "firsts : ", firsts
        #---------------------------------- #rem = (v % arr[0].val) + arr[0].val
        #------------------------------------------------ rem = (v % arr[0].val)
        #--------------------------------------------- #print "remaining " , rem
        #---------------------------------------------------------- pdigits = []
        #---------------------------------------------------- dig = arr[0].index
        #--------------------------------------------- for i in range(len(arr)):
            #-- if rem - (arr[i].val - arr[0].val) >= 0 and arr[i].index >= dig:
                #------------------------------------------- #dig = arr[i].index
                #---------------------------------- pdigits.append(arr[i].index)
                #------------------------------ rem -= (arr[i].val - arr[0].val)
                #------------------------------------ #print "remaining : ", rem

        res = unb_knapsack(arr, v)
        #print "unb kpsack", res
        res = sorted(res, reverse=True)
        print "".join(map(str, res))
        #--------------------------------------------------------- print pdigits
        #------------------------------- pdigits = sorted(pdigits, reverse=True)
#------------------------------------------------------------------------------ 
        #------------------------- for i in range(num_of_digits - len(pdigits)):
            #-------------------------------------- pdigits.append(arr[0].index)
            
        #print pdigits
            
        #print "".join(map(str, pdigits[:num_of_digits]))
