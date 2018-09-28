import sys
ival = raw_input()
n = raw_input()
pat = [0]*256
patcount = 0

for i in range(len(n)):
    if pat[ord(n[i])] < 1:
        pat[ord(n[i])] = 1
        patcount += 1

strr = [0]*256
count = 0
start = 0
minlen = sys.maxsize
for i in range(len(n)):
    strr[ord(n[i])] += 1
    #print strr
    if pat[ord(n[i])] != 0 and strr[ord(n[i])] <= pat[ord(n[i])]:
        count += 1
    if count == patcount:
        while pat[ord(n[start])] == 0 or strr[ord(n[start])] > pat[ord(n[start])]:
            if strr[ord(n[start])] > pat[ord(n[start])]:
                strr[ord(n[start])] -= 1
            start += 1
        m = i - start + 1
        if m < minlen:
            minlen = m
print minlen