
import sys
t = int(raw_input())
ls = []
for i in range(t):
    n = int(raw_input())
    arr = map(int, raw_input().split())
    ls.append(arr)
    #print ls

for lst in ls:
    li = sorted(lst, reverse=True)
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
            m = a/b+b/a
            #print " a, b ", a, b, " :: m ", m
            if m < minval:
                minval = m
                a1 = a
                b1 = b
        b = a
    print b1, b1, a1, a1

