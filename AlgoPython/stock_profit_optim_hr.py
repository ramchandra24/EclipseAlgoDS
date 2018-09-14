#!/bin/python

def stockmax(prices):
    i = len(prices) - 1
    maxx = prices[i]
    profit = 0
    while i >= 0:
        if prices[i] < maxx:
            profit += maxx - prices[i]
        else:
            maxx = prices[i]
        i -= 1
    return profit
    
    
if __name__ == '__main__':
    prices = [5, 2, 6, 8, 1, 7, 3, 4]
    print prices
    result = stockmax(prices)
    print "Max profit : ", result