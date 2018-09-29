#!/bin/python

def getVal(dtuple):
    return dtuple[1]

def getKey(dtuple):
    return dtuple[0]

# Complete the minimumLoss function below.
def minimumLoss(price):
    pdict = {}
    for i in range(len(price)):
        pdict[i] = price[i]

    titems = sorted(pdict.items(), key=getVal)
    print "sorted list : ", titems
    mmin = getVal(titems[1]) - getVal(titems[0])
    for i in range(1, len(titems)):
        if getKey(titems[i]) > getKey(titems[i-1]):
            continue
        if getVal(titems[i]) < getVal(titems[i-1]):
            continue
        print "i-1 : ", i-1, " :: i : ", i
        if mmin > (getVal(titems[i]) -getVal(titems[i-1])):
            mmin = getVal(titems[i]) - getVal(titems[i-1])
            
    return mmin
    
    
if __name__ == '__main__':
    price = [20, 7, 8, 2, 5]
    result = minimumLoss(price)
    print "Minimum loss : ", result

