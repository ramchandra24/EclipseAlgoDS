class node:
    def __init__(self):
        self.val = 0
        self.index = 0
        
    def printNode(self):
        print self.index, " : ", self.val
        
def cond(a, b):
    #print "comparing : ", a.val, " with ", b.val
    diff = a.val - b.val
    if 0 == diff:
        return b.index - a.index
    return diff


v = int(raw_input())
a = map(int, raw_input().split(' '))

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
    firsts = v / arr[0].val - 1
    #print "firsts : ", firsts
    rem = (v % arr[0].val) + arr[0].val
    #print "remaining " , rem
    dig = arr[0].index
    for i in range(len(arr)):
        if rem - arr[i].val >= 0 and arr[i].index >= dig:
                dig = arr[i].index

    digits = []
    op = ""
    if dig > arr[0].index :
        digits.append(dig)
    
    for i in range(firsts):
        #print arr[0].index
        #op.join(str(arr[0].index))
        digits.append(arr[0].index)
    

    if dig <= arr[0].index :
        digits.append(dig)
    
    print "".join(map(str, digits))
