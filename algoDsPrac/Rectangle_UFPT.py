


import sys

def findMax(a):
    maxx = a[0]
    for i in range(1, len(a)):
        if a[i] > maxx:
            maxx = a[i]
    return maxx

def csorte(a):
    
    c = [0] * (findMax(a)+1)
    for i in range(len(a)):
        c[a[i]] += 1

    lst = []
    for i in range(len(c)):
        if c[i] < 2:
            continue
        lst.append(i)
        lst.append(i)
        if c[i] >= 4:
            lst.append(i)
            lst.append(i)
    return lst

t = int(raw_input())
ans = []
for j in range(t):
    n = int(raw_input())
    lst = map(int, raw_input().split())
    li = csorte(lst)
    #sorted(lst, reverse=True)
    #print li
    i = 1
    a1 = b1 = 0
    a = b = 0
    minval = sys.maxsize
    while i < len(li):
        while li[i] != li[i-1]:
            i += 1
        a = li[i]
        i += 2
        if a > 0 and b > 0:
            m = a/float(b)+b/float(a)
            #print " a ", a, " :: b ", b, " :: m ", m
            if m < minval:
                minval = m
                a1 = a
                b1 = b
            if a == b:
                break
        b = a
    ans.append([b1, b1, a1, a1])

for it in ans:
    print ' '.join(map(str, it))
#    ls.append(arr)
    #print ls

#for lst in ls:

