#!/bin/python

def findProfit(prices, pmax, imax):
    pro = 0
    buy = 0
    print "arr : ", prices[pmax:imax+1]
    for i in range(pmax, imax+1):
        buy += prices[i]
    pro = prices[imax]*(i+1-pmax) - buy
    print "profit : ", pro
    return pro
        
# Complete the stockmax function below.
def stockmax(prices):
    
    imax = 0
    tpro = 0
    j = 0
    while j < len(prices):
        pmax = imax
        maxx = prices[imax]
        print "maxx : ", maxx
        for i in range(imax+1, len(prices)):
            if prices[i] > maxx:
                imax = i
                maxx = prices[imax]
                print "max i : ", imax, " :: max val : ", maxx

        if pmax != imax:
            tpro += findProfit(prices, pmax, imax)
        j = imax + 1
        imax = j
    return tpro
    
    
if __name__ == '__main__':
    prices = [5, 2, 6, 8, 1, 7, 3, 4]
    result = stockmax(prices)
    print "Max profit : ", result