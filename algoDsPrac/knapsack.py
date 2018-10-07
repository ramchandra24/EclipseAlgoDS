class kpsac:
    def __init__(self, val, wt):
        self.wt = wt
        self.val = val
        
    def knapsack(self, W):
        karr = [[0 for j in range(W+1)] for i in range(len(self.val)+1)]
        for i in range(len(self.val)+1):
            for j in range(W+1):
                if i == 0 or j == 0:
                    karr[i][j] = 0
                elif self.wt[i-1] > j:
                    karr[i][j] = karr[i-1][j]
                else:
                    karr[i][j] = max(karr[i-1][j], karr[i-1][j-self.wt[i-1]]+self.val[i-1])
        
        for ro in karr:
            print ro
        
        return karr[len(self.val)][W]
        
        
val = [60, 100, 120] 
wt = [10, 20, 30] 

kpobj = kpsac(val, wt)
kret = kpobj.knapsack(60)
print kret
