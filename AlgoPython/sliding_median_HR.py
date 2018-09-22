#!/bin/python

import math
import os
import random
import re
import sys

def swapp(a, i, j):
    if i != j:
        ae = a[i]
        a[i] = a[j]
        a[j] = ae

def partition(a, p, r):
    random.seed()
    pi = 0
    if r > 0:
        pi += random.randrange(r)
    pi += p
    print "rand pivot index : ", pi, " : pivot elem : ", a[pi]
    swapp(a, pi, p)
    pv = a[p]
    less = p
    more = p+1
    for i in range(p+1, r):
        if a[i] > pv:
            more += 1
        else:
            less += 1
            swapp(a, less, more)
            more += 1
    
    swapp(a, p, less)
    print "pivot : ", pv, " pivot idx : ", less, " arr : ", a[p:r]
    return less

def findRank(a, rank, p, q):
    k = partition(a, p, q)
    curRank = k - p + 1
    print "curRank : ", curRank, " : finding rank : ", rank
    if curRank == rank:
        #print "rank elem return : ", a[k]
        return a[k]
    elif curRank > rank:
        return findRank(a, rank, p, k-1)
    else:
        return findRank(a, rank-curRank, k+1, q)
    


def mediannn(expenditure, i, j, d):
    #x = partition(expenditure, 0, len(expenditure)) 
    arr = expenditure[i:j]
    l = len(arr)
    if l % 2 != 0:
        m = findRank(arr, l/2+1, 0, l)
        print "odd m : ", m
        return m
    m1 = findRank(arr, l/2, 0, l)
    print "even m1 : ", m1
    m2 = findRank(arr, l/2+1, 0, l)
    print "even m2 : ", m2
    
    return ((m1+m2)/2.0)

def mediann(expenditure, i, j, d):
    arr = expenditure[i:j]
    arr = sorted(arr)
    #print "arr : ", arr
    if len(arr) % 2 == 1:
        return (arr[len(arr)/2])
    return (arr[len(arr)/2] + arr[len(arr)/2+1])/2.0

# Complete the activityNotifications function below.
def activityNotifications(expenditure, d):
    l = len(expenditure)
    #m = median(expenditure, 0, l, d)
    #print "median : ", m
    #print "full sorted: ", sorted(expenditure)
    #print "array : ", expenditure
    count = 0
    for i in range(0, l-d):
        m = mediannn(expenditure, i, i+d, d)
        print "median : ", m
        print "expen : ", expenditure[i+d]
        if expenditure[i+d] >= 2*m:
            count += 1
    return count
    

if __name__ == '__main__':
    expenditure = [1, 4, 3, 2, 4]
    result = activityNotifications(expenditure, 3)
    
    print "Total notifications : ", result
